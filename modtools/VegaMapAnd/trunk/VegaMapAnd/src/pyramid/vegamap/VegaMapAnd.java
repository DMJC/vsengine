/// VegaMap - Vega Strike universe map viewer.
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 */
  
/// Version: see below in __VERSION__
/// Author: pyramid
/// Created: 2012-04-10

package pyramid.vegamap;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Vector;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ListActivity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.ParseException;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.text.util.Linkify;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

public class VegaMapAnd extends ListActivity {
    
    public static Context context;

	// menu entries
    private static final int MENU_ABOUT = 1;
	private static final int MENU_CONFIG = 2;
    private static final int MENU_EXIT = 3;
    private static final int DIALOG_ABOUT = 1;
	private static final String DATA_DIR = "/data/";
    
    private LayoutInflater mInflater;
    private Vector<RowData> data;
    private RowData rd;
	private SoundManager sound;

	private String __VERSION__;
    private String baseDir; // application data base dir
    private List<String> sMapFiles;
    private List<String> sMapTitles;
    private List<String> sMapDetails;
    private List<Integer> iMapSource;
	private String sUrl;
	private boolean bPlayMusic = false;
    boolean bWriteableExternalStorage = false;
 
    //---------------------------------------------------------------
    // Activity Functions
    //---------------------------------------------------------------

    // Invoked when the Activity is created.
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //Log.i(this.getClass().getName(), "--starting VegaMapAnd");

        context = this;
        sound = new SoundManager();
		sMapFiles = new Vector<String>();
		sMapTitles = new Vector<String>();
		sMapDetails = new Vector<String>();
		iMapSource = new Vector<Integer>();
        
        // load splash
        boolean bAlreadyRunning = true;
        if (savedInstanceState == null) {
        	bAlreadyRunning = false;
        }
        if (!bAlreadyRunning) {
        	loadSplash();
        }

        // layout & info
        //setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_SENSOR);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_UNSPECIFIED);
        getVersion();

        // verify sd card
        bWriteableExternalStorage = checkExternalStorage();

        readSettings();
		
        // create catalog
        Log.i(this.getClass().getName(), "bWriteableExternalStorage : " + bWriteableExternalStorage);
        if (bWriteableExternalStorage) {
            createAppDirectory();
            loadExternalCatalog();
        }
		loadInternalCatalog();
		assignCatalogTitles();
        createCatalog();

    }

    // Invoked when the Activity loses user focus.
    @Override
    protected void onPause() {
        super.onPause();
        sound.onPause();
    }

    @Override
    protected void onStop() {
        super.onStop();
		sound.onStop();
    }

    @Override
    protected void onResume() {
        super.onResume();
		readSettings();
        if(bPlayMusic) {
    		sound.createPlaylist();
    		sound.setRandomPosition();
    		sound.loopPlaylist();
        }
    }

    // Invoked during init to give the Activity a chance to set up its Menu.
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        menu.add(0, MENU_ABOUT, 0, "About & Help");
        menu.add(0, MENU_CONFIG, 0, "Settings");
        menu.add(0, MENU_EXIT, 0, "Exit");
        return super.onCreateOptionsMenu(menu);
    }

     // Invoked when the user selects an item from the Menu.
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case MENU_ABOUT:
            	showDialog(DIALOG_ABOUT);
                return true;
            case MENU_EXIT:
                this.finish();
                return true;
	        case MENU_CONFIG:
	        	showOptions();
                return true;
	        default:
                return super.onOptionsItemSelected(item);
        }
    }

    // use back key to exit about screen 
    public void onBackPressed() {
    	//this.finish();
		quit();
    }
	
    public void quit() {
        int pid = android.os.Process.myPid();
        android.os.Process.killProcess(pid);
        System.exit(0);
    }
	
    // Notification to give the Activity a chance to save state.
    @Override
    protected void onSaveInstanceState(Bundle outState) {
        // just have the view's thread saves its state into the Bundle
        super.onSaveInstanceState(outState);
     }
    
    //---------------------------------------------------------------
    // Main Functions
    //---------------------------------------------------------------
    
    private void readSettings() {
        bPlayMusic = PreferenceManager.getDefaultSharedPreferences(context).getBoolean("use_sound", false);
    }

    private boolean checkExternalStorage() {

    	boolean mExternalStorageWriteable = false;
    	String state = Environment.getExternalStorageState();

    	if (Environment.MEDIA_MOUNTED.equals(state)) {
    	    // We can read and write the media
    	    mExternalStorageWriteable = true;
    	} else if (Environment.MEDIA_MOUNTED_READ_ONLY.equals(state)) {
    	    // We can only read the media
    	    mExternalStorageWriteable = false;
    	} else {
    	    // Something else is wrong. It may be one of many other states, but all we need
    	    //  to know is we can neither read nor write
    	    mExternalStorageWriteable = false;
    	}
    	return mExternalStorageWriteable;

    }

    private void createAppDirectory() {
    	baseDir = Environment.getExternalStorageDirectory() + DATA_DIR + this.getPackageName() + File.separator;
    	File folder = new File(baseDir);
    	if (!folder.canWrite()) {
            Log.w(this.getClass().getName(), "Unable to write folder " + folder);
    	}
        try {
	        if(!folder.exists()){
	        	folder.mkdirs();
	            Log.i(this.getClass().getName(), "created folder: " + folder);
	        }
        } catch (Exception e) {
            // Unable to create file, likely because external storage is
            // not currently mounted.
            Log.e("ExternalStorage", "Error creating " + folder, e);
        }
    }

    private void loadSplash() {
                startActivity(new Intent().setClassName("pyramid.vegamap", "pyramid.vegamap.SplashScreen"));
    }

    private void getVersion() {
    	// http://www.eridem.net/android-tip-008-getting-application-version-and-other-package-information
    	try {
      	  PackageManager manager = getApplicationContext().getPackageManager();
      	  PackageInfo info = manager.getPackageInfo(
      			getApplicationContext().getPackageName(), 0);
      	__VERSION__ = info.versionName;
      	} catch (Exception e) {
      	  Log.e(this.getClass().getName(), "Error getting version");
      	}
    	
    }

    private void showOptions() {
        Intent optionsActivity = new Intent(getBaseContext(), Settings.class);
        startActivity(optionsActivity);
    }

    //---------------------------------------------------------------
    // Dialogs
    //---------------------------------------------------------------

	@Override
    protected void onPrepareDialog (int id, Dialog dialog) {
        switch(id) {
        	case DIALOG_ABOUT:
	            removeDialog(DIALOG_ABOUT);
        		break;
        }
    }
    
    protected Dialog onCreateDialog(int id) {
        Dialog dialog = null;
        AlertDialog.Builder builder;
        switch(id) {
        case DIALOG_ABOUT:
			String sMusic = "";
			if (bPlayMusic & sound!=null) {
				sMusic = "Currently playing:\n" + sound.getTrackName() + "\n\n";
			}
        	builder = new AlertDialog.Builder(this);
        	builder.setIcon(R.drawable.ic_launcher);
        	builder.setTitle("VegaMapAnd");
			final TextView text = new TextView(this);
			text.setText("Vega Strike Universe Maps\n" +
				"Version " + __VERSION__+ "\n" +
				"(c) pyramid 2012\n\n" +
				"Vega Strike is a space simulation engine. " +
				"The supplied maps are from games developed with the engine. " +
				"Visit: vegastrike.sf.net for more info\n\n" +
				sMusic +
				"Instructions:\n" +
				"- Select an existing map to view\n" +
				"- Long press a map for context menu with more options\n" +
				"\n" +
				"Inmap navigation:\n" +
				"- Swipe to scroll the map.\n" +
				"- Tap screen to see on-screen menu.\n" +
				"- Pinch or use zoom buttons to (surprise!) zoom.\n" +
				"- Use menu button to change display options.\n" +
				"- An 'S' indicator will show when all systems are displayed.\n" +
				"- A 'J' indicator will show after finished jump network resolution.\n" +
				"- An 'A' indicates auto navigation mode is enabled.\n" +
                "- An 'P' indicates path selection mode is active.\n" +
				"- Long tap to select start and end of path.\n" +
				"- Press back key twice to exit the map.\n" +
				"\n" +
				"Note:\n" +
				"Please report possible bugs on the market or on the Vega Strike forum.\n" +
				"");
			Linkify.addLinks(text, Linkify.WEB_URLS);
			builder.setView(text);	
            dialog = builder.create();
            break;
        default:
            dialog = null;
        }
        return dialog;
    }

	@Override
	public boolean onContextItemSelected(MenuItem item) {
		// Take action on selection of a context menu item
		
	    Uri webUri = Uri.parse("http://" + sUrl);
	    Intent webIntent = new Intent(Intent.ACTION_VIEW).setData(webUri);
	    startActivity(webIntent);
	    return true;
	}
	
	@Override
	public void onCreateContextMenu(ContextMenu menu, View v, ContextMenuInfo menuInfo) {
		// Create item specific menu
		//http://www.mikeplate.com/2010/01/21/show-a-context-menu-for-long-clicks-in-an-android-listview/
		AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) menuInfo;
		// don't web link unknown maps
		if (sMapDetails.get(info.position).equals("")) {
		    return;
		}

		menu.setHeaderTitle(sMapTitles.get(info.position));
		sUrl = sMapDetails.get(info.position);

		// construct the menu
		menu.add(Menu.NONE, 0, 0, "View web page");
		
	}
	
    //---------------------------------------------------------------
    // Catalog View
    //---------------------------------------------------------------

	private void showMap(String sMapFile, boolean bUseExtDir) {
        //Log.i(this.getClass().getName(), "--showMap");
        
        // these will return the actual dpi horizontally and vertically
        DisplayMetrics dm = new DisplayMetrics();
        getWindowManager().getDefaultDisplay().getMetrics(dm);
        int iScreenDensity = dm.densityDpi;
    	
    	// start the map view
    	Intent map = new Intent().setClassName("pyramid.vegamap", "pyramid.vegamap.VegaMapView");
    	map.putExtra("sMapFile", sMapFile);
		map.putExtra("bUseExtDir", bUseExtDir);
		map.putExtra("bPlayMusic", bPlayMusic);
    	map.putExtra("iScreenDensity", iScreenDensity);
        startActivity(map);    	
    }
	
    private void loadInternalCatalog() {
    	//Log.i(this.getClass().getName(), "--loadInternalCatalog");
        AssetManager assetManager = getAssets();
        String assets[] = null;
		
        try {
            assets = assetManager.list("maps");
            if (assets.length == 0) { // file
				return;
            } else { // dir
                for (int i = 0; i < assets.length; i++) {
					sMapFiles.add(assets[i]);
					sMapTitles.add("");
					sMapDetails.add("");
					iMapSource.add(0);
                }
            }
        } catch (IOException ex) {
            Log.e(this.getClass().getName(), "I/O Exception", ex);
        }

		 // sort entries alphabetically
		 ArrayList<String> maps = new ArrayList<String>();
		 for (int i=0; i<sMapFiles.size(); i++) {
			 maps.add(sMapFiles.get(i));
		 }
		 Collections.sort(maps);
		 for (int i=0; i<maps.size(); i++) {
			 sMapFiles.set(i, maps.get(i));
		 }
	}

    private void loadExternalCatalog() {
    	//Log.i(this.getClass().getName(), "--loadCatalog");		
    	baseDir = Environment.getExternalStorageDirectory() + DATA_DIR + this.getPackageName() + File.separator; 
    	File folder = new File(baseDir);
    	File[] filelist = folder.listFiles();
    	if (filelist==null) return;

		List<String> sFiles = new Vector<String>();
        //create the catalog list
    	for (int i=0; i<filelist.length; i++) {
            if (!filelist[i].isDirectory()) {
				sFiles.add(filelist[i].getName());
            }
    	} //for

		// sort entries alphabetically
		ArrayList<String> maps = new ArrayList<String>();
		for (int i=0; i<sFiles.size(); i++) {
			maps.add(sFiles.get(i));
		}
		Collections.sort(maps);
		for (int i=0; i<maps.size(); i++) {
			sMapFiles.add(maps.get(i));
			sMapTitles.add("");
			sMapDetails.add("");
			iMapSource.add(1);
		}
    }
	
	private void assignCatalogTitles() {
    	// assign titles
    	for (int i=0; i< sMapFiles.size(); i++) {
        	sMapTitles.set(i, sMapFiles.get(i)); //"Vega Strike Map";
			sMapDetails.set(i, "");
			if (sMapFiles.get(i).equals("vegastrike.xml")) {
				sMapTitles.set(i, "Vega Strike\nUpon The Coldest Sea");
				sMapDetails.set(i, "vegastrike.sf.net");
			}
			if (sMapFiles.get(i).equals("stuniverse.xml")) {
				sMapTitles.set(i, "Vega Trek");
                sMapDetails.set(i, "vegatrek.sourceforge.net");
			}
			if (sMapFiles.get(i).equals("puuniverse.xml")) {
				sMapTitles.set(i, "Privateer Parallel Universe");
                sMapDetails.set(i, "pu.wcjunction.com");
			}
 			if (sMapFiles.get(i).equals("piauniverse.xml")) {
				sMapTitles.set(i, "PI Armada");
                sMapDetails.set(i, "sourceforge.net/projects/piarmada/");
			}
            if (sMapFiles.get(i).equals("pgguniverse.xml")) {
                sMapTitles.set(i, "Privateer Gemini Gold");
                sMapDetails.set(i, "privateer.sourceforge.net");
            }
		}
    	
    }

	public void onListItemClick(ListView parent, View v, int position, long id) {
		boolean bUseExtDir = false;
		if (iMapSource.get(position)==1) {
			bUseExtDir = true;			
		}
	    showMap(sMapFiles.get(position), bUseExtDir);
		//Toast.makeText(getApplicationContext(), "You have selected " + (position+1)+"the item " + sMapFiles[position],  Toast.LENGTH_SHORT).show();
	}
    
    private Bitmap loadImage(String imgFileName) {
        //Log.i(this.getClass().getName(), "imgFileName=" + imgFileName );
        if (imgFileName==null) return null;
		Bitmap bitmapImage = BitmapFactory.decodeFile(imgFileName);
		return bitmapImage;
    }

    private class RowData {
	    protected int mId;
	    protected String mTitle;
	    protected String mDetail;
	    
	    RowData(int id, String title, String detail) {
		    mId = id;
		    mTitle = title;
		    mDetail = detail;
	    }
	    
    	@Override
	    public String toString() {
	            return mId + " " + mTitle + " " + mDetail;
	    }
    	
	}

    private void createCatalog() {
    	
        setContentView(R.layout.catalog);
        mInflater = (LayoutInflater) getSystemService(Activity.LAYOUT_INFLATER_SERVICE);

        data = new Vector<RowData>();

        for(int i=0;i<sMapFiles.size();i++){

        try {
			String sTitle = sMapTitles.get(i);
			if (iMapSource.get(i)==1) {
				sTitle += " (*)";
			}
         	rd = new RowData(i, sTitle, sMapDetails.get(i));
            } catch (ParseException e) {
            	e.printStackTrace();
           }
           data.add(rd);
        }
        CustomAdapter adapter = new CustomAdapter(this, R.layout.catalog_list, R.id.title, data);
        setListAdapter(adapter);
        getListView().setTextFilterEnabled(true);
        registerForContextMenu(getListView());
        
    }

    private class CustomAdapter extends ArrayAdapter<RowData> {

    	public CustomAdapter(Context context, int resource, int textViewResourceId, List<RowData> objects) {               
    		super(context, resource, textViewResourceId, objects);
    	}
    	
        @Override
        public View getView(int position, View convertView, ViewGroup parent) {   

        	//Log.i(this.getClass().getName(), "showing= " + position);
	        ViewHolder holder = null;
	        TextView title = null;
	        TextView detail = null;
	        ImageView image = null;
	        RowData rowData = getItem(position);
	        
	        if(null == convertView) {
	            convertView = mInflater.inflate(R.layout.catalog_list, null);
	            holder = new ViewHolder(convertView);
	            convertView.setTag(holder);
    	    }
	        
            holder = (ViewHolder) convertView.getTag();
            title = holder.gettitle();
            title.setText(rowData.mTitle);
            detail = holder.getdetail();
            detail.setText(rowData.mDetail);                                                     

            // set image in view 
            image = holder.getImage();
            String fileName = baseDir + sMapFiles.get(rowData.mId) + ".jpg";
            if (new File(fileName).exists()) {
            	image.setImageBitmap(loadImage(fileName));
            } else {
                image.setImageResource(R.drawable.catalog);

            }
            return convertView;
    	}
    	      
	    private class ViewHolder {
	    	private View mRow;
	    	private TextView title = null;
	    	private TextView detail = null;
	    	private ImageView i11 = null; 

	    	public ViewHolder(View row) {
	    	    mRow = row;
	    	}
	    	  
	    	public TextView gettitle() {
	    		if(null == title){
	    		  title = (TextView) mRow.findViewById(R.id.title);
	    		}
	    		return title;
	    	}     

	    	public TextView getdetail() {
	    		if(null == detail){
	    		  detail = (TextView) mRow.findViewById(R.id.detail);
	    		}
	    		return detail;
	    	}
	    	
	    	public ImageView getImage() {
	    		if(null == i11){
	    			i11 = (ImageView) mRow.findViewById(R.id.img);
	    		}
	    		return i11;
            }
	    	  
       } //ViewHolder
	      
     } //CustomAdapter    	      
    
}
