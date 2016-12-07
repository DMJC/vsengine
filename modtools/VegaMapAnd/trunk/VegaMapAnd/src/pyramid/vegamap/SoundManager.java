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

import java.io.File;
import java.util.List;
import java.util.Vector;

import android.content.Context;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.os.Environment;
import android.util.Log;

public class SoundManager {

	public boolean useExtDir = true;
	public String baseDir = "";

	private static final String DATA_DIR = "/data/";
	private static final String DIR_MUSIC = "music";
	private static final String extension = ".ogg";
	
	private Context mContext;
    private MediaPlayer mSoundPlayer;
    private MediaPlayer mMusicPlayer[];
    private Thread mFadeThread;
    
    private String sFileName;
	private int iCurrentPlayer = 0;
	private int iPreviousPlayer = 1;
	private float fMusicVolume = 1.0f;
	private float fSoundVolume = 1.0f;
	private List<String> playlist;
	private int iPlaylistPosition = 0;
	
	public SoundManager() {
		mContext = VegaMapAnd.context;
        
        mMusicPlayer = new MediaPlayer[2];
        mSoundPlayer = new MediaPlayer();
    	//mSoundPlayer.setLooping(false);
		playlist = new Vector<String>();
		
	}

	public void createPlaylist() {
		if (!useExtDir) {
			return;
		}
    	baseDir = Environment.getExternalStorageDirectory() + DATA_DIR + mContext.getPackageName() + File.separator + DIR_MUSIC + File.separator;
		
    	File folder = new File(baseDir);
    	File[] filelist = folder.listFiles();
    	if (filelist==null) return;		
		
		// count the directories
    	for (int i=0; i<filelist.length; i++) {
			sFileName = filelist[i].getName();
			if (!filelist[i].isDirectory() & sFileName.substring(sFileName.length()-4).equals(extension)) {
				playlist.add(filelist[i].getName());	
            }
    	} //for	
	}
	
	public void loopPlaylist() {
		if (playlist.size()==0) {return;}
		sFileName = baseDir + playlist.get(iPlaylistPosition);
		if (new File(sFileName).exists()) {
			try {
				//setNextMusicPlayer();
				mMusicPlayer[iCurrentPlayer] = new MediaPlayer();
				mMusicPlayer[iCurrentPlayer].setDataSource(sFileName);
				mMusicPlayer[iCurrentPlayer].prepare();
				mMusicPlayer[iCurrentPlayer].start();
    			mMusicPlayer[iCurrentPlayer].setLooping(false);
				mMusicPlayer[iCurrentPlayer].setVolume(fMusicVolume, fMusicVolume);
			} catch (Exception e) {
				Log.e(this.getClass().getName(), "error: " + e.getMessage(), e);
			}
		}
		mMusicPlayer[iCurrentPlayer].setOnCompletionListener(new OnCompletionListener() {
			public void onCompletion(MediaPlayer musicPlayer) {
				if (iPlaylistPosition < playlist.size() - 1) {
	                iPlaylistPosition++;
	            } else {
					iPlaylistPosition = 0;
				}
				musicPlayer.reset();
				// Change Current Song here using the set data source method and whatever else must change
				sFileName = baseDir + playlist.get(iPlaylistPosition);
				try {
					musicPlayer.setDataSource(sFileName);
					musicPlayer.prepare();
    				musicPlayer.setLooping(false);
					musicPlayer.setVolume(fMusicVolume, fMusicVolume);
					musicPlayer.start();
				} catch (Exception e) {
					Log.e(this.getClass().getName(), "error: " + e.getMessage(), e);
				}
	        }
	    });

	}
	
	public void setPlaylistPosition(int pos) {
		iPlaylistPosition = pos;
	}

	public void setRandomPosition() {
		int pos = (int)((playlist.size()-1) * Math.random());
		iPlaylistPosition = pos;
	}
	
	public String getTrackName() {
		return playlist.get(iPlaylistPosition);
	}

    public void fadeOutSound() {
    	
	    mFadeThread = new Thread() {
	    	boolean _active = true;
	    	int _fadeTime = 200;
		    float level = fSoundVolume;

		    @Override
	        public void run() {
	           try {
	               int waited = 0;
	               while (_active && waited < _fadeTime) {
	                   sleep(10);
	                   if(_active) {
	                       waited += 10;
	         	           if(mMusicPlayer[iPreviousPlayer] != null){
	         		           level = level * 0.9f;
	         		           mMusicPlayer[iPreviousPlayer].setVolume(level, level);
	         		       }
	                   }
	               }
	            } catch (InterruptedException e) {
					Log.e(this.getClass().getName(), "error: " + e.getMessage(), e);
				}
	        }
	    };
	     
	    mFadeThread.start();
    }

    public void fadeOutMusic() {
    	
	    mFadeThread = new Thread() {
	    	boolean _active = true;
	    	int _fadeTime = 500;
		    float level = fMusicVolume;

		    @Override
	        public void run() {
	           try {
	               int waited = 0;
	               while (_active && waited < _fadeTime) {
	                   sleep(10);
	                   if(_active) {
	                       waited += 10;
	         	           if(mMusicPlayer[iPreviousPlayer] != null){
	         		           level = level * 0.95f;
	         		           mMusicPlayer[iPreviousPlayer].setVolume(level, level);
	         		       }
	                   }
	               }
	           } catch (InterruptedException e) {
				   Log.e(this.getClass().getName(), "error: " + e.getMessage(), e);
	           }
	        }
	    };
	     
	    mFadeThread.start();
    }
 
    public void onPause() {
    	
        if (mMusicPlayer[0] != null) {
        	mMusicPlayer[0].pause();
        }
        if (mMusicPlayer[1] != null) {
        	mMusicPlayer[1].pause();
        }
        if (mSoundPlayer != null) {
        	mSoundPlayer.pause();
        }
    	
    }

    public void onResume() {
        if (mMusicPlayer[0] != null) {
        	mMusicPlayer[0].start();
        }
        if (mMusicPlayer[1] != null) {
        	mMusicPlayer[1].start();
        }
        if (mSoundPlayer != null) {
        	mSoundPlayer.start();
        }
    }

    public void onStop() {
    	
    	if (mFadeThread != null) {
    		mFadeThread.stop();
    		mFadeThread = null;
    	}
        if (mMusicPlayer[0] != null) {
        	mMusicPlayer[0].stop();
        	mMusicPlayer[0].release();
        	mMusicPlayer[0] = null;
        }
        if (mMusicPlayer[1] != null) {
        	mMusicPlayer[1].stop();
        	mMusicPlayer[1].release();
        	mMusicPlayer[1] = null;
        }
        if (mSoundPlayer != null) {
        	mSoundPlayer.stop();
        	mSoundPlayer.release();
        	mSoundPlayer = null;
        }
        
    }
    
    public void setNextMusicPlayer() {
    	if (iCurrentPlayer == 0) {
    		iCurrentPlayer = 1;
    		iPreviousPlayer = 0;
    	} else {
    		iCurrentPlayer = 0;
    		iPreviousPlayer = 1;
    	}

    }
    
}
