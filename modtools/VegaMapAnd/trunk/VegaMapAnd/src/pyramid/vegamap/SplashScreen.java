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

// http://www.codeproject.com/KB/android/AndroidSplash.aspx

import android.app.Activity;
import android.os.Bundle;
import android.view.MotionEvent;
 
public class SplashScreen extends Activity {
	
	protected boolean _active = true;
	protected int _splashTime = 200; // 2000; time to display the splash screen in ms
    private Thread mSplashThread;    
	
   /** Called when the activity is first created. */
   @Override
   public void onCreate(Bundle savedInstanceState) {
      super.onCreate(savedInstanceState);
      setContentView(R.layout.splash);

      mSplashThread = new Thread() {
         @Override
         public void run() {
            try {
               int waited = 0;
               while (_active && waited < _splashTime) {
                  sleep(100);
                  if(_active) {
                      waited += 100;
                  }
               }
            } catch (InterruptedException e) {
               // do nothing
            } finally {
               finish();
            }
         }
      };
      
      mSplashThread.start();
   }

   // Processes splash screen touch events
   @Override
   public boolean onTouchEvent(MotionEvent evt)
   {
       if(evt.getAction() == MotionEvent.ACTION_DOWN)
       {
           synchronized(mSplashThread){
               mSplashThread.notifyAll();
           }
       }
       return true;
   }    
   
   
}