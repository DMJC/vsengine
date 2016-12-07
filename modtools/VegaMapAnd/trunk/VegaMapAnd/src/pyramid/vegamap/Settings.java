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
 
import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.CheckBoxPreference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceCategory;
import android.preference.PreferenceManager;
import android.preference.PreferenceScreen;

public class Settings extends PreferenceActivity {
	
	SharedPreferences appPreferences;
	protected PreferenceScreen modScenePref;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setPreferenceScreen(createPreferenceHierarchy());
    }

    private PreferenceScreen createPreferenceHierarchy() {
        // Root
        PreferenceScreen root = getPreferenceManager().createPreferenceScreen(this);
        // Get the app's shared preferences
        appPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        // Get the value for the run counter
        int usageCounter = appPreferences.getInt("counter", 0);
        
        // Inline preferences 
        PreferenceCategory generalPrefCat = new PreferenceCategory(this);
        generalPrefCat.setTitle("Application");
        root.addPreference(generalPrefCat);
        
        // Usage counter display
        PreferenceScreen usagePref = getPreferenceManager().createPreferenceScreen(this);
        usagePref = getPreferenceManager().createPreferenceScreen(this);
        usagePref.setKey("usage_counter");
        usagePref.setTitle("Usage statistic");
        usagePref.setSummary("This application was used " + usageCounter + " times");
        generalPrefCat.addPreference(usagePref);

        // Center cross preference
        CheckBoxPreference ccPref = new CheckBoxPreference(this);
        ccPref.setKey("show_center");
        ccPref.setTitle("Center Indicator");
        ccPref.setSummary("Check to show center cross.");
        ccPref.setDefaultValue(true);
        generalPrefCat.addPreference(ccPref);

        // Distance ruler preference
        CheckBoxPreference drPref = new CheckBoxPreference(this);
        drPref.setKey("show_ruler");
        drPref.setTitle("Distance Ruler");
        drPref.setSummary("Check to show distance ruler.");
        drPref.setDefaultValue(true);
        generalPrefCat.addPreference(drPref);

        // Remember position preference
        CheckBoxPreference rpPref = new CheckBoxPreference(this);
        rpPref.setKey("last_position");
        rpPref.setTitle("Remember Last Position");
        rpPref.setSummary("Check to start map on last visited position.");
        rpPref.setDefaultValue(true);
        generalPrefCat.addPreference(rpPref);
		
        // Soundtrack preference
        CheckBoxPreference soundPref = new CheckBoxPreference(this);
        soundPref.setKey("use_sound");
        soundPref.setTitle("Play Soundtrack");
        soundPref.setSummary("Check to play soundtrack from sdcard/data/pyramid.vegamap/music.");
        soundPref.setDefaultValue(false);
        generalPrefCat.addPreference(soundPref);

        // Debugging preferences
        CheckBoxPreference fpsPref = new CheckBoxPreference(this);
        //Log.i(this.getClass().getName(), "use FPS: " + showFps);
        fpsPref.setKey("show_debuginfo");
        fpsPref.setTitle("Show Debug Info");
        fpsPref.setSummary("Tick to show frame rate and some universe parameters.");
        generalPrefCat.addPreference(fpsPref);
        
        // Increment the counter
        SharedPreferences.Editor editor = appPreferences.edit();
        editor.putInt("counter", ++usageCounter);
        editor.commit(); // important commit

        return root;
    }
    
}
