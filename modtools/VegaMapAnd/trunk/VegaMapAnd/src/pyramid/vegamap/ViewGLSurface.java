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

import android.os.Vibrator;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.opengl.GLSurfaceView;
import android.view.GestureDetector;
import android.view.GestureDetector.OnGestureListener;
import android.view.MotionEvent;
import android.view.ScaleGestureDetector;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.AutoCompleteTextView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
//import android.util.Log;

public class ViewGLSurface extends GLSurfaceView implements OnGestureListener {

    public ViewGLRenderer mRenderer;
    public float zoomFactor = 1.0f;
	
	private Context context;
    private GestureDetector mGestureDetector;
    private ScaleGestureDetector mScaleDetector;
	private AlertDialog.Builder findDialog;
	private float deltaX;
	private float deltaY;
	private String sLastSearch = "";
	
    public ViewGLSurface(Context context) {
        super(context);
		//Log.i(this.getClass().getName(), "--ViewGLSurface");
		this.context = context;		
        mRenderer = new ViewGLRenderer(context);
        mGestureDetector = new GestureDetector(this);
        mScaleDetector = new ScaleGestureDetector(context, new ScaleListener());
        setRenderer(mRenderer);
        setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
        //setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
        //requestRender();		
		
    }
 
    @Override
    public boolean onTouchEvent(final MotionEvent event) {
    	mScaleDetector.onTouchEvent(event);
        	mGestureDetector.onTouchEvent(event);
		return true;	
	}
	
    private class ScaleListener extends ScaleGestureDetector.SimpleOnScaleGestureListener {
    	//http://stackoverflow.com/questions/5790503/can-we-use-scale-gesture-detector-for-pinch-zoom-in-android
        @Override
        public boolean onScale(ScaleGestureDetector detector) {
        	zoomFactor *= detector.getScaleFactor();
			if (mRenderer.camDistZ>10000 & zoomFactor<mRenderer.zoomFactor) {
				return true;	
			}
			if (mRenderer.camDistZ<=0.1 & zoomFactor>mRenderer.zoomFactor) {
				return true;	
			}
		    // Don't let the object get too small or too large.
        	mRenderer.zoomFactor = Math.max(0.1f, Math.min(zoomFactor, 100.0f));
            return true;
        }
    }
	
    public boolean onDown(MotionEvent e)
    {
        //Log.i(this.getClass().getName(), "- DOWN -");
        return true;
    }

    public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY)
    {
        //Log.i(this.getClass().getName(), "- FLING -");
        return false;
    }

    public void onLongPress(MotionEvent e)
    {
        //Log.i(this.getClass().getName(), "- LONG PRESS -");
		if (mRenderer==null) { return; }
		if (mRenderer.mGalaxyView==null) { return; }
		// formerly: recenter
		//mRenderer.moveX = 0;
		//mRenderer.moveY = 0;
		
        mRenderer.mGalaxyView.bPathSelectMode = true;
		Vibrator v = (Vibrator) context.getSystemService(Context.VIBRATOR_SERVICE);
		v.vibrate(100);
		float px = (float)(mRenderer.viewPortMin.x + (mRenderer.viewPortMax.x - mRenderer.viewPortMin.x)*e.getX()/mRenderer.screenWidth);
		float py = (float)(mRenderer.viewPortMin.y + (mRenderer.viewPortMax.y - mRenderer.viewPortMin.y)*e.getY()/mRenderer.screenHeight);
		
		mRenderer.mGalaxyView.selectSystem(new float[] {px,py});
		
    }

    public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY)
    {
        //Log.i(this.getClass().getName(), "- SCROLL -");
		// ignore accidental micro moves
		// doesn't work well
		//if (Math.abs(distanceX)<5 | Math.abs(distanceY)<5) {
		//	return true;			
		//}
		
		// avoid moving too far out of universe bounds
		if (distanceX<0 & (mRenderer.viewPortMax.x)<=mRenderer.mGalaxyView.center_x_min) {
			return true;	
		}
		if (distanceX>0 & (mRenderer.viewPortMin.x)>=mRenderer.mGalaxyView.center_x_max) {
			return true;	
		}
		if (distanceY<0 & (mRenderer.viewPortMax.y)<=mRenderer.mGalaxyView.center_y_min) {
			return true;	
		}
		if (distanceY>0 & (mRenderer.viewPortMin.y)>=mRenderer.mGalaxyView.center_y_max) {
			return true;	
		}
		deltaX = distanceX*0.5f*mRenderer.universeSize/mRenderer.zoomFactor;
		deltaY = distanceY*0.5f*mRenderer.universeSize/mRenderer.zoomFactor;
		mRenderer.moveX = mRenderer.moveX + deltaX;
		mRenderer.moveY = mRenderer.moveY + deltaY;
        mRenderer.mGalaxyView.moveX = mRenderer.moveX;
		mRenderer.mGalaxyView.moveY = mRenderer.moveY;
		mRenderer.setViewPort();
		return true;
    }
    
    public void onShowPress(MotionEvent e)
    {
        //Log.i(this.getClass().getName(), "- SHOW PRESS -");
    }

    public boolean onSingleTapUp(MotionEvent event)
    {
        //Log.i(this.getClass().getName(), "- SINGLE TAP UP -");

        // touch event positions
    	// x=0: left, x=max: right
    	// y=0: top; y=max: bottom
        int x = (int)event.getX();
        int y = (int)event.getY();
	
		if (mRenderer==null) {
			return true;
		}
		
		//zoom-in
		if(y>=mRenderer.screenHeight-100*mRenderer.fScreenScale
		   & x>=mRenderer.screenWidth-120*mRenderer.fScreenScale) {
			if (mRenderer.camDistZ<0.1 | mRenderer.camDistZ<0.1) {
				return true;	
			}
			zoomFactor = zoomFactor*1.1f;
			mRenderer.zoomFactor = zoomFactor;
	        mRenderer.setViewPort();
		}
		//zoom-out
        if(y>=mRenderer.screenHeight-100*mRenderer.fScreenScale
		   & x<=mRenderer.screenWidth-120*mRenderer.fScreenScale & x>=mRenderer.screenWidth-240*mRenderer.fScreenScale) {
			if (mRenderer.camDistZ>10000 | mRenderer.camDistZ<0.1) {
				return true;	
			}
			zoomFactor = zoomFactor*0.9f;
			mRenderer.zoomFactor = zoomFactor;
	        mRenderer.setViewPort();
		}
		//menu button
		if(y>=mRenderer.screenHeight-100*mRenderer.fScreenScale & x<=120*mRenderer.fScreenScale) {
			mRenderer.bShowMenu = !mRenderer.bShowMenu;
		}
		//menu left
		int posxmin = (int)(10*mRenderer.fScreenScale);
		int posxmax = (int)(160*mRenderer.fScreenScale);
        if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-410*mRenderer.fScreenScale & y<=mRenderer.screenHeight-340*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
            mRenderer.mGalaxyView.toggleFlag("show_jump_lines");       
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
        }
        if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-300*mRenderer.fScreenScale & y<=mRenderer.screenHeight-230*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
            mRenderer.mGalaxyView.toggleFlag("show_no_jumps");       
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
        }
        if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-190*mRenderer.fScreenScale & y<=mRenderer.screenHeight-120*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
            mRenderer.mGalaxyView.toggleFlag("show_sector_boxes");       
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
        }
		//menu center
   		posxmin = (int)(170*mRenderer.fScreenScale);
		posxmax = (int)(320*mRenderer.fScreenScale);
		if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-410*mRenderer.fScreenScale & y<=mRenderer.screenHeight-340*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
            mRenderer.mGalaxyView.toggleFlag("show_system_name");       
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
        }
        if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-300*mRenderer.fScreenScale & y<=mRenderer.screenHeight-230*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
            mRenderer.mGalaxyView.toggleFlag("show_system_faction");       
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
        }
        if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-190*mRenderer.fScreenScale & y<=mRenderer.screenHeight-120*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
            mRenderer.mGalaxyView.toggleFlag("show_system_sector");       
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
        }
		//menu right
   		posxmin = (int)(330*mRenderer.fScreenScale);
		posxmax = (int)(480*mRenderer.fScreenScale);
		if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-410*mRenderer.fScreenScale & y<=mRenderer.screenHeight-340*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
            mRenderer.mGalaxyView.toggleFlag("show_compass");       
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
        }
        if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-300*mRenderer.fScreenScale & y<=mRenderer.screenHeight-230*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
            mRenderer.mGalaxyView.toggleFlag("show_homeworlds");       
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
        }
        if(mRenderer.bShowMenu & y>=mRenderer.screenHeight-190*mRenderer.fScreenScale & y<=mRenderer.screenHeight-120*mRenderer.fScreenScale & x>=posxmin & x<=posxmax) {
  			showSearch();
            mRenderer.bShowMenu = !mRenderer.bShowMenu;
  		}
		
        return true;
    }
	
	private void showSearch() {
		findDialog = new AlertDialog.Builder(context);
		findDialog.setTitle("Find system");
		
		LinearLayout lin = new LinearLayout(context);
		
        // Create auto complete view
        final AutoCompleteTextView textInputField = new AutoCompleteTextView(context);
        textInputField.setWidth(mRenderer.screenWidth);
        textInputField.setDropDownHeight(ViewGroup.LayoutParams.FILL_PARENT);
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(context, R.layout.autocomplete_item, mRenderer.mGalaxyView.systems.sortedNames);
        textInputField.setAdapter(adapter);
        textInputField.setText(sLastSearch);
        textInputField.setThreshold(1);
		
		// Set text view to get user input 
        TextView text = new TextView(context);
        lin.addView(textInputField);
        lin.addView(text,0,(int)(mRenderer.screenHeight*0.4));
		findDialog.setView(lin);	

		findDialog.setPositiveButton("Find", new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int whichButton) {
					String sysname = textInputField.getText().toString();
					sLastSearch = sysname;
					findSystem(sysname);
				}
			});		
		findDialog.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
				public void onClick(DialogInterface dialog, int whichButton) {
				}
			});
		findDialog.show();

	}

    class FindSystem extends Thread {
        private String sysName;

        FindSystem(String sysName) {
            this.sysName = sysName;
        }

        @Override
        public void run() {
			if (sysName.equals("")) { return; }
			int idx = mRenderer.mGalaxyView.systems.sysName.indexOf(sysName);
			if (idx==-1) {
				return;
			}
			Point3D pos = mRenderer.mGalaxyView.systems.sysPos.get(idx);
			mRenderer.navigateTo(pos);
			
			try {
                this.finalize();
            } catch (Throwable e) {
                e.printStackTrace();
            }
        } //run

    }

    public void findSystem(String sysName) {
        FindSystem mThread = new FindSystem(sysName);
        mThread.start();
    }

	public void backPressed() {
		Toast.makeText(context, "Press back key twice to exit map",  Toast.LENGTH_SHORT).show();		
	}
	
}
