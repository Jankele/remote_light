package com.led.led;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.bluetooth.BluetoothSocket;
import android.view.View;
import android.widget.Switch;
import android.widget.Toast; //needed for displaying alerts
import android.widget.CompoundButton;
import android.widget.Button;
import android.app.ProgressDialog;
import android.os.AsyncTask;
import android.content.Intent; //moving between activities
import android.bluetooth.BluetoothAdapter; //getting info about bluetooth adapter installed on user equipment
import android.bluetooth.BluetoothDevice; //getting info about bluetooth devices paired with user equipment

import java.io.IOException;
import java.util.UUID;


public class classLED extends AppCompatActivity
{
    //@widgets
    Switch btnS1, btnS2, btnS3;
    Button btnPrOn, btnPrOff, btnPirOn, btnPirOff, btnBleOn, btnBleOff, btnConfiguration;
    //@variables
    String address = null;
    String config = null;
    private ProgressDialog progress;
    //@bluetooth
    BluetoothAdapter myBluetooth = null;
    BluetoothSocket btSocket = null;
    private boolean isBtConnected = false;
    //SPP UUID. this standard id for serial port communication
    static final UUID myUUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

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
    protected void onNewIntent(Intent intent) { //on exit from config activity send info to arduino
        config = intent.getStringExtra(classConfigurations.EXTRA_CONFIGURATION);
        msg(config);
        switch (config) {
            case "Fotorezystor":
                    sendByte("g");
                    break;
            case "Czujka PIR":
                    sendByte("h");
                    break;
            case "Moduł Bluetooth":
                    sendByte("i");
                    break;
            case "Fotorezystor i Czujka PIR":
                    sendByte("j");
                    break;
            case "Fotorezystor i Moduł Bluetooth":
                    sendByte("k");
                    break;
            case "Czujka PIR i Moduł Bluetooth":
                    sendByte("l");
                    break;
            case "Fotorezystor, Czujka PIR i Moduł Bluetooth":
                    sendByte("m");
                    break;
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) //startup method
    {
        super.onCreate(savedInstanceState);

        Intent newint = getIntent();
        address = newint.getStringExtra(classPairList.EXTRA_ADDRESS); //receive the address of the bluetooth device

        setContentView(R.layout.activity_led);

        //call the widgtes
       /* btnS1 = (Switch)findViewById(R.id.switch1);
        btnS2 = (Switch)findViewById(R.id.switch2);
        btnS3 = (Switch)findViewById(R.id.switch3);*/
        btnPrOn = (Button) findViewById(R.id.button9);
        btnPrOff = (Button) findViewById(R.id.button4);
        btnPirOn = (Button) findViewById(R.id.button5);
        btnPirOff = (Button) findViewById(R.id.button6);
        btnBleOn = (Button) findViewById(R.id.button7);
        btnBleOff = (Button) findViewById(R.id.button8);
        btnConfiguration = (Button)findViewById(R.id.button2);

        new ConnectBT().execute(); //Call the class to connect
/*
        btnS1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
        {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//photoresistor led(red)
                if (isChecked) {
                    sendByte("a"); //ON
                } else {
                    sendByte("b"); //OFF
                }
            }
        });

        btnS2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
        {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//pir sensor led(green)
                if (isChecked) {
                    sendByte("c"); //ON
                } else {
                    sendByte("d"); //OFF
                }
            }
        });

        btnS3.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener()
        {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {//bluetooth adapter led(white)
                if (isChecked) {
                    sendByte("e"); //ON
                } else {
                    sendByte("f"); //OFF
                }
            }
        });
*/
        btnPrOn.setOnClickListener(new View.OnClickListener() {//photoresistor led(red) ON
            @Override
            public void onClick(View v) {
                sendByte("a");
            }
        });

        btnPrOff.setOnClickListener(new View.OnClickListener() {//photoresistor led(red) OFF
            @Override
            public void onClick(View v) {
                sendByte("b");
            }
        });

        btnPirOn.setOnClickListener(new View.OnClickListener() {//pir sensor led(green) ON
            @Override
            public void onClick(View v) {
                sendByte("c");
            }
        });

        btnPirOff.setOnClickListener(new View.OnClickListener() { //pir sensor led(green) OFF
            @Override
            public void onClick(View v) {
                sendByte("d");
            }
        });

        btnBleOn.setOnClickListener(new View.OnClickListener() { //bluetooth adapter led(white) ON
            @Override
            public void onClick(View v) {
                sendByte("e");
            }
        });

        btnBleOff.setOnClickListener(new View.OnClickListener() { //bluetooth adapter led(white) OFF
            @Override
            public void onClick(View v) {
                sendByte("f");
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
    }

    private void sendByte(String a) //this method sends byte to arduino
    {
        if (btSocket!=null)
        {
            try
            {
                btSocket.getOutputStream().write(a.getBytes());
            }
            catch (IOException e)
            {
                msg("Błąd");
            }
        }
    }

    // fast way to call Toast alert
    private void msg(String s)
    {
        Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();
    }


    private class ConnectBT extends AsyncTask<Void, Void, Void>  // UI thread
    {
        private boolean ConnectSuccess = true; //if it's here, it's almost connected

        @Override
        protected void onPreExecute()
        {
            progress = ProgressDialog.show(classLED.this, "Łączenie", "Proszę Czekać");  //show a progress dialog
        }

        @Override
        protected Void doInBackground(Void... devices) //while the progress dialog is shown, the connection is done in background
        {
            try
            {
                if (btSocket == null || !isBtConnected)
                {
                    myBluetooth = BluetoothAdapter.getDefaultAdapter();//get the user equipment's bluetooth adapter
                    BluetoothDevice dispositivo = myBluetooth.getRemoteDevice(address);//connects to the device's address and checks if it's available
                    btSocket = dispositivo.createInsecureRfcommSocketToServiceRecord(myUUID);//create a RFCOMM (SPP) connection
                    BluetoothAdapter.getDefaultAdapter().cancelDiscovery();
                    btSocket.connect();//start connection
                }
            }
            catch (IOException e)
            {
                ConnectSuccess = false;//if the try failed, you can check the exception here
            }
            return null;
        }
        @Override
        protected void onPostExecute(Void result) //after the doInBackground, it checks if everything went fine
        {
            super.onPostExecute(result);

            if (!ConnectSuccess)
            {
                msg("Połączenie Nieudane");
                finish();
            }
            else
            {
                msg("Połączono");
                isBtConnected = true;
            }
            progress.dismiss();
        }
    }
}
