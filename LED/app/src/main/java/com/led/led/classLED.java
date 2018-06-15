package com.led.led;

import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.bluetooth.BluetoothSocket;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.Toast; //needed for displaying alerts
import android.widget.Button;
import android.content.Intent; //moving between activities
import android.bluetooth.BluetoothAdapter; //getting info about bluetooth adapter installed on user equipment
import android.bluetooth.BluetoothDevice; //getting info about bluetooth devices paired with user equipment

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;

public class classLED extends AppCompatActivity
{

    //@widgets
    Switch btnS1, btnS2, btnS3;
    Button btnConfiguration;
    Handler bluetoothIn;
    //@bluetooth
    String config = null;
    private BluetoothAdapter btAdapter = null;
    private BluetoothSocket btSocket = null;
    private ConnectedThread mConnectedThread;
    //used to identify handler message
    final int handlerState = 0;
    private boolean toSwitch = true;
    // SPP UUID service - this should work for most devices
    private static final UUID BTMODULEUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    //on exit from config activity send info to arduino
    @Override
    protected void onNewIntent(Intent intent) {
        config = intent.getStringExtra(classConfigurations.EXTRA_CONFIGURATION);
        msg(config);
        switch (config)
        {
            case "Fotorezystor":
                mConnectedThread.write("g");
                break;
            case "Czujka PIR":
                mConnectedThread.write("h");
                break;
            case "Moduł Bluetooth":
                mConnectedThread.write("i");
                break;
            case "Fotorezystor i Czujka PIR":
                mConnectedThread.write("j");
                break;
            case "Fotorezystor i Moduł Bluetooth":
                mConnectedThread.write("k");
                break;
            case "Czujka PIR i Moduł Bluetooth":
                mConnectedThread.write("l");
                break;
            case "Fotorezystor, Czujka PIR i Moduł Bluetooth":
                mConnectedThread.write("m");
                break;
        }
    }

    @Override
    public void onBackPressed() {
        if (btSocket!=null) //If the btSocket is busy
        {
            try
            {
                btSocket.close(); //close connection
            }
            catch (IOException e)
            { msg("Błąd");}
        }
        finish(); //return to the first layout
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_led);

        btnConfiguration = findViewById(R.id.button2);
        btnS1 = findViewById(R.id.switch1);
        btnS2 = findViewById(R.id.switch2);
        btnS3 = findViewById(R.id.switch3);

        bluetoothIn = new Handler() {
            public void handleMessage(android.os.Message msg) {
                    switch ((String) msg.obj)
                    {
                        case "a":
                            toSwitch = false;
                            btnS1.setChecked(true);
                            break;
                        case "b":
                            toSwitch = false;
                            btnS1.setChecked(false);
                            break;
                        case "c":
                            toSwitch = false;
                            btnS2.setChecked(true);
                            break;
                        case "d":
                            toSwitch = false;
                            btnS2.setChecked(false);
                            break;
                    }
                }
        };

        btnS1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
        {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//photoresistor led(red)
                if(toSwitch) {
                    if (isChecked) {
                        mConnectedThread.write("a"); //ON
                    } else {
                        mConnectedThread.write("b"); //OFF
                    }
                }
                toSwitch = true;
            }
        });
        btnS2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
        {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//pir sensor led(green)
                if (toSwitch) {
                    if (isChecked) {
                        mConnectedThread.write("c"); //ON
                    } else {
                        mConnectedThread.write("d"); //OFF
                    }
                }
                toSwitch = true;
            }
        });
        btnS3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
        {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//bluetooth adapter led(white)
                if(toSwitch) {
                    if (isChecked) {
                        mConnectedThread.write("e"); //ON
                    } else {
                        mConnectedThread.write("f"); //OFF
                    }
                }
                toSwitch = true;
            }
        });

        btAdapter = BluetoothAdapter.getDefaultAdapter();       // get Bluetooth adapter
        checkBTState();

        btnConfiguration.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i = new Intent(classLED.this, classConfigurations.class);
                //Change the activity.
                startActivity(i);
            }
        });

        msg("Łączenie...");
        //Get MAC address from DeviceListActivity via intent
        Intent intent = getIntent();

        // String for MAC address
        String address;
        //Get the MAC address from the DeviceListActivty via EXTRA
        address = intent.getStringExtra(classPairList.EXTRA_ADDRESS);



        //create device and set the MAC address
        BluetoothDevice device = btAdapter.getRemoteDevice(address);

        try {
            btSocket = createBluetoothSocket(device);
        } catch (IOException e) {
            msg("Socket creation failed");
        }
        // Establish the Bluetooth socket connection.
        BluetoothAdapter.getDefaultAdapter().cancelDiscovery();
        try
        {
            btSocket.connect();
        } catch (IOException e) {
            try {
                btSocket.close();
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        }
        mConnectedThread = new ConnectedThread(btSocket);
        mConnectedThread.start();

        //I send a character when resuming.beginning transmission to check device is connected
        //If it is not an exception will be thrown in the write method and finish() will be called
        mConnectedThread.write("x");

        msg("Połączono");
    }


    // fast way to call Toast alert
    private void msg(String s)
    {
        Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
    }

    private BluetoothSocket createBluetoothSocket(BluetoothDevice device) throws IOException {

        return  device.createRfcommSocketToServiceRecord(BTMODULEUUID);
        //creates secure outgoing connecetion with BT device using UUID
    }


    //Checks that the Android device Bluetooth is available and prompts to be turned on if off
    private void checkBTState() {

        if(btAdapter==null) {
            Toast.makeText(getBaseContext(), "Device does not support bluetooth", Toast.LENGTH_LONG).show();
        } else {
            if (btAdapter.isEnabled()) {
            } else {
                Intent enableBtIntent = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(enableBtIntent, 1);
            }
        }
    }

    //create new class for connect thread
    private class ConnectedThread extends Thread {
        private final InputStream mmInStream;
        private final OutputStream mmOutStream;

        //creation of the connect thread
        public ConnectedThread(BluetoothSocket socket) {
            InputStream tmpIn = null;
            OutputStream tmpOut = null;

            try {
                //Create I/O streams for connection
                tmpIn = socket.getInputStream();
                tmpOut = socket.getOutputStream();
            } catch (IOException e) { }

            mmInStream = tmpIn;
            mmOutStream = tmpOut;
        }


        public void run() {
            byte[] buffer = new byte[256];
            int bytes;

            // Keep looping to listen for received messages
            while (true) {
                try {
                    bytes = mmInStream.read(buffer);        	//read bytes from input buffer
                    String readMessage = new String(buffer, 0, bytes);
                    // Send the obtained bytes to the UI Activity via handler
                    bluetoothIn.obtainMessage(handlerState, bytes, -1, readMessage).sendToTarget();
                } catch (IOException e) {
                    break;
                }
            }
        }
        //write method
        public void write(String input) {
            byte[] msgBuffer = input.getBytes();           //converts entered String into bytes
            try {
                mmOutStream.write(msgBuffer);                //write bytes over BT connection via outstream
            } catch (IOException e) {
                //if you cannot write, close the application
                Toast.makeText(getBaseContext(), "Connection Failure", Toast.LENGTH_LONG).show();
                finish();

            }
        }
    }
}