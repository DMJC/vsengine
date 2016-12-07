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

package pyramid.vegamap;

import android.app.Activity;
import android.content.SharedPreferences;
import android.content.pm.ActivityInfo;
import android.media.AudioManager;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.WindowManager;

public class VegaMapView extends Activity {

    private ViewGLSurface mViewGL;
    private String sMapFile;
	private boolean bUseExtDir;
	private boolean bPlayMusic;
    private int iScreenDensity;
	private int iKeyPressed = 0;
	private long lLastKey = 0;

	@Override
	public void onCreate(Bundle savedInstanceState) {
	    super.onCreate(savedInstanceState);

	    //setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);
        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_UNSPECIFIED);
        setKeepScreenOn(this, true);
        // set volume control to media
        setVolumeControlStream(AudioManager.STREAM_MUSIC);
	    
	    Bundle extras = getIntent().getExtras();
	    sMapFile = extras.getString("sMapFile");
		bUseExtDir = extras.getBoolean("bUseExtDir");
		bPlayMusic = extras.getBoolean("bPlayMusic");
	    iScreenDensity = extras.getInt("iScreenDensity");
	}
	
    // use back key to exit about screen 
    public void onBackPressed() {
		iKeyPressed += 1;
		if (iKeyPressed==1) {
			lLastKey = System.currentTimeMillis();
			mViewGL.backPressed();
		}
		if (iKeyPressed==2) {
			if (System.currentTimeMillis()-lLastKey<=2000) {
				this.finish();				
			} else {
				iKeyPressed = 0;
			}
		}
    }
	
    public void setKeepScreenOn(Activity activity, boolean keepScreenOn) {
        if(keepScreenOn) {
          activity.getWindow().
            addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        } else {
          activity.getWindow().
            clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        }
      }

    @Override
    protected void onPause() {
        // take appropriate action when the activity looses focus
        super.onPause();
        saveData();
        mViewGL.mRenderer.onPause();
    }

    @Override
    protected void onResume() {
        // take appropriate action when the activity regains focus
        super.onResume();
        createRenderer();
        readData();
        mViewGL.mRenderer.onResume();
    }
    
    private void createRenderer() {
    	if (mViewGL == null) {
	        mViewGL = new ViewGLSurface(this);
	        mViewGL.mRenderer.iScreenDensity = iScreenDensity;
			mViewGL.mRenderer.fScreenScale = (float)iScreenDensity/(float)240;
	        mViewGL.mRenderer.setMapFile(sMapFile, bUseExtDir, bPlayMusic);
	        setContentView(mViewGL);
	        mViewGL.setFocusableInTouchMode(true);
    	}
    }

    private void saveData() {

    	// Store values between instances here
    	SharedPreferences data = getSharedPreferences("MapPosition", 0);
		SharedPreferences.Editor editor = data.edit();
		
		editor.putFloat(sMapFile + "-moveX", mViewGL.mRenderer.moveX);
		editor.putFloat(sMapFile + "-moveY", mViewGL.mRenderer.moveY);
		editor.putFloat(sMapFile + "-zoom", mViewGL.mRenderer.zoomFactor);
		
		// Commit to storage
		editor.commit();
    }

    private void readData() {		
        boolean bRecallPosition = PreferenceManager.getDefaultSharedPreferences(this).getBoolean("last_position", true);		
		if (bRecallPosition) {
    		SharedPreferences data = getSharedPreferences("MapPosition", 0);
    		mViewGL.mRenderer.moveX = data.getFloat(sMapFile+"-moveX", 0);
    		mViewGL.mRenderer.moveY = data.getFloat(sMapFile+"-moveY", 0);
    		mViewGL.mRenderer.zoomFactor = data.getFloat(sMapFile+"-zoom", 1);
		}
	}

}
