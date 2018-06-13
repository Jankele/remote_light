package com.led.led;

import android.os.Handler;
import android.support.constraint.ConstraintLayout;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.bluetooth.BluetoothSocket;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.ProgressBar;
import android.widget.RelativeLayout;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast; //needed for displaying alerts
import android.widget.Button;
import android.app.ProgressDialog;
import android.os.AsyncTask;
import android.content.Intent; //moving between activities
import android.bluetooth.BluetoothAdapter; //getting info about bluetooth adapter installed on user equipment
import android.bluetooth.BluetoothDevice; //getting info about bluetooth devices paired with user equipment

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.UUID;

import static android.R.attr.progressBarStyleLarge;


public class classLED extends AppCompatActivity
{

    //@widgets
    Switch btnS1, btnS2, btnS3;
    Button btnPrOn, btnPrOff, btnPirOn, btnPirOff, btnBleOn, btnBleOff, btnConfiguration;
    Handler bluetoothIn;

    String config = null;
    final int handlerState = 0;        				 //used to identify handler message
    private BluetoothAdapter btAdapter = null;
    private BluetoothSocket btSocket = null;
    private ProgressDialog progress;

    private ConnectedThread mConnectedThread;

    // SPP UUID service - this should work for most devices
    private static final UUID BTMODULEUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    // String for MAC address
    private static String address;

    @Override
    protected void onNewIntent(Intent intent) { //on exit from config activity send info to arduino
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

        //Link the buttons and textViews to respective views
        btnPrOn = findViewById(R.id.button9);
        btnPrOff = findViewById(R.id.button4);
        btnPirOn = findViewById(R.id.button5);
        btnPirOff = findViewById(R.id.button6);
        btnBleOn = findViewById(R.id.button7);
        btnBleOff = findViewById(R.id.button8);
        btnConfiguration = findViewById(R.id.button2);
        btnS1 = findViewById(R.id.switch1);
        btnS2 = findViewById(R.id.switch2);
        btnS3 = findViewById(R.id.switch3);

        bluetoothIn = new Handler() {
            public void handleMessage(android.os.Message msg) {
                if (msg.what == handlerState) {										//if message is what we want
                    String readMessage = (String) msg.obj;
                    switch (readMessage)
                    {
                        case "a":
                            msg("Dioda Czerwona została włączona");
                            break;
                        case "b":
                            msg("Dioda Czerwona została wyłączona");
                            break;
                        case "c":
                            msg("Dioda Zielona została włączona");
                            break;
                        case "d":
                            msg("Dioda Zielona została wyłączona");
                            break;
                        case "e":
                            msg("Dioda Biała została włączona");
                            break;
                        case "f":
                            msg("Dioda Biała została wyłączona");
                            break;
                    }
                }
            }
        };

//        btnS1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
//        {
//            @Override
//            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//photoresistor led(red)
//                if (isChecked) {
//                    mConnectedThread.write("a"); //ON
//                } else {
//                    mConnectedThread.write("b"); //OFF
//                }
//            }
//        });
//        btnS2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
//        {
//            @Override
//            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//pir sensor led(green)
//                if (isChecked) {
//                    mConnectedThread.write("c"); //ON
//                } else {
//                    mConnectedThread.write("d"); //OFF
//                }
//            }
//        });
//        btnS3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
//        {
//            @Override
//            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//bluetooth adapter led(white)
//                if (isChecked) {
//                    mConnectedThread.write("e"); //ON
//                } else {
//                    mConnectedThread.write("f"); //OFF
//                }
//            }
//        });

        btAdapter = BluetoothAdapter.getDefaultAdapter();       // get Bluetooth adapter
        checkBTState();

        btnPrOn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                mConnectedThread.write("a");
            }
        });

        // Set up onClick listeners for buttons to send 1 or 0 to turn on/off LED
        btnPrOff.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                mConnectedThread.write("b");
            }
        });

        btnPirOn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                mConnectedThread.write("c");    // Send "1" via Bluetooth
            }
        });

        // Set up onClick listeners for buttons to send 1 or 0 to turn on/off LED
        btnPirOff.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                mConnectedThread.write("d");    // Send "0" via Bluetooth
            }
        });

        btnBleOn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                mConnectedThread.write("e");    // Send "1" via Bluetooth
            }
        });

        // Set up onClick listeners for buttons to send 1 or 0 to turn on/off LED
        btnBleOff.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                mConnectedThread.write("f");    // Send "0" via Bluetooth
            }
        });

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
            try
            {
                btSocket.close();
            } catch (IOException e2)
            {
                //insert code to deal with this
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