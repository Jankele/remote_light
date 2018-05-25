package com.led.led;

import android.content.Intent; //moving between activities
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.AdapterView; //initiate list view
import android.widget.ArrayAdapter; //fill list view
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;


public class classConfigurations extends AppCompatActivity
{
    //widgets
    ListView configurationList;
    public static String EXTRA_CONFIGURATION = "configuration";

    @Override
    public void onBackPressed() {
        finish(); //return to the first layout
    }
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_configurations);

        //Calling widgets
        configurationList = (ListView)findViewById(R.id.listView2);

        ArrayList list = new ArrayList();
        list.add("Fotorezystor");
        list.add("Czujka PIR");
        list.add("Moduł Bluetooth");
        list.add("Fotorezystor i Czujka PIR");
        list.add("Fotorezystor i Moduł Bluetooth");
        list.add("Czujka PIR i Moduł Bluetooth");
        list.add("Fotorezystor, Czujka PIR i Moduł Bluetooth");



        final ArrayAdapter adapter = new ArrayAdapter(this,android.R.layout.simple_list_item_1, list);
        configurationList.setAdapter(adapter);
        configurationList.setOnItemClickListener(myListClickListener); //Method called when the device from the list is clicked
        

    }

    private AdapterView.OnItemClickListener myListClickListener = new AdapterView.OnItemClickListener()
    {
        public void onItemClick (AdapterView<?> av, View v, int arg2, long arg3)
        {

            String config = ((TextView) v).getText().toString();


            Intent i = new Intent(classConfigurations.this, classLED.class);
            i.putExtra(EXTRA_CONFIGURATION, config);
            i.setFlags(Intent.FLAG_ACTIVITY_REORDER_TO_FRONT);
            startActivity(i);
        }
    };
}
