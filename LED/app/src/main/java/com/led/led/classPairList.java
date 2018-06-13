package com.led.led;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.content.Intent; //moving between activities
import android.view.View;
import android.widget.TextView;
import android.widget.AdapterView; //initiate list view
import android.widget.ArrayAdapter; //fill list view
import android.widget.Button;
import android.widget.ListView;
import android.bluetooth.BluetoothAdapter; //getting info about bluetooth adapter installed on user equipment
import android.bluetooth.BluetoothDevice; //getting info about bluetooth devices paired with user equipment

import java.util.ArrayList;
import java.util.Set;

public class classPairList extends AppCompatActivity
{
    // @widgets

    ListView pairList;
    // @bluetooth
    private BluetoothAdapter myBluetooth = null;
    private Set<BluetoothDevice> pairedDevices;
    public static String EXTRA_ADDRESS = "address";

    @Override
    protected void onResume() {
        super.onResume();
        pairedDevicesList();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) //startup method
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pair_list);
        //call the widgtes

        pairList = (ListView)findViewById(R.id.listView);

        myBluetooth = BluetoothAdapter.getDefaultAdapter(); //assign bluetooth adapter from user equipment to variable

        if(!myBluetooth.isEnabled()) //if bluetooth adapter is turned off, turn it on in separate window
        {
            Intent i = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
            startActivityForResult(i,1);
        }

    }

    private void pairedDevicesList() //create list of bluetooth devices paired with user equipment
    {
        //@bluetooth
        pairedDevices = myBluetooth.getBondedDevices(); //get paired devices
        ArrayList list = new ArrayList();

        if (pairedDevices.size()>0)
        {
            for(BluetoothDevice bt : pairedDevices)
            {
                list.add(bt.getName() + "\n" + bt.getAddress()); //add each entry from pairedDevices to list
            }
        }
        //fill listview with elements from list created above
        final ArrayAdapter adapter = new ArrayAdapter(this,android.R.layout.simple_list_item_1, list);
        pairList.setAdapter(adapter);
        pairList.setOnItemClickListener(myListClickListener); //set click listener on listview elements
    }

    private AdapterView.OnItemClickListener myListClickListener = new AdapterView.OnItemClickListener()
    {
        public void onItemClick (AdapterView<?> av, View v, int arg2, long arg3)
        {
            String sub = ((TextView) v).getText().toString();
            int length = sub.length() - 17; //extract device pshysical address
            String address = sub.substring(length);

            Intent i = new Intent(classPairList.this, classLED.class);
            i.putExtra(EXTRA_ADDRESS, address);
            startActivity(i); //pass physical address to led activity and start it.
        }
    };
}
