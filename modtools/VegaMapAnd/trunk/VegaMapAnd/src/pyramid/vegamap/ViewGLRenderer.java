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
  
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.opengl.GLU;
import android.preference.PreferenceManager;
import android.util.Log;

// Renderer
public class ViewGLRenderer implements GLSurfaceView.Renderer {

    public GalaxyView mGalaxyView;
    public boolean bShowMenu = false;
	public int iState = 0;
    public int iScreenDensity = 240; //standard for 480x800 for 10.2cm display
	public float fScreenScale = 1.0f; // density based scale factor
    public float zoomFactor = 1.0f;
    public float centerX = 0.0f;
    public float centerY = 0.0f;
    public float moveX = 0.0f;
    public float moveY = 0.0f;
    public float universeSize = 1.0f;
    public Point3D viewPortMin = new Point3D(0,0,0);
    public Point3D viewPortMax = new Point3D(0,0,0);
	public float camDistZ;

    public final String DATA_DIR = "/data/"; 
    public final int STATE_PAUSED = 0;
	public static final int STATE_STARTING = 1;
	public static final int STATE_PRELOADING = 2;
	public static final int STATE_LOADING = 3;
	public static final int STATE_RUNNING = 4;

    private Context context;
    private GL10 gl;
    private GLSprite sprites;
    private GLText font; 
    private GLDraw draw;
	private Galaxy galaxy;
	private SoundManager sound;

	private boolean useExtDir = false;
	private boolean bRendererIsRunning = false;
	private boolean bShowDebug = false;
	private boolean bShowCenter = true;
	private boolean bShowRuler = true;
    public int screenWidth;
    public int screenHeight;
    private float screenRatio; //width/height = 0.6
    private float fLastFrameRate = 0;
    private float fBaseFontSize = 2.0f;
    private float fFontSize = 2.0f;    
    private long lFrameTime;
	private String sMapFile = null;
    private String sSprites[];
	private float screenLy;
	
    //------------------------------------------
    // Initialization Functions
    //------------------------------------------
    
    public ViewGLRenderer(Context context) {
        this.context = context;
        sprites = new GLSprite(gl, context);
		sound = new SoundManager();
		draw = new GLDraw();
		
        //load sprites
        sSprites = new String[] {
            "ui_backdrop", "ui_quickmenu", "ui_zoom_in", "ui_zoom_out", "ui_menu",
            "ui_compass", "ui_icon_j", "ui_icon_s", "ui_icon_a", "spr_planet",
			"ui_icon_p", "spr_star_unknown", "spr_star_nojumps",
            "spr_star_01", "spr_star_02", "spr_star_03", "spr_star_04", "spr_star_05",
            "spr_star_06", "spr_star_07", "spr_star_08", "spr_star_09", "spr_star_10",
            "spr_star_11", "spr_star_12", "spr_star_13", "spr_star_14", "spr_star_15",
            "spr_star_16", "spr_star_17", "spr_star_18", "spr_star_19", "spr_star_20",
            "spr_star_21", "spr_star_22", "spr_star_23", "spr_star_24", "spr_star_25",
            "spr_star_26", "spr_star_27", "spr_star_28", "spr_star_29", "spr_star_30",
            "spr_star_31", "spr_star_32", "spr_star_33", "spr_star_34", "spr_star_35",
            "spr_star_36", "spr_star_37", "spr_star_38", "spr_star_39", "spr_star_40",
            "spr_star_41", "spr_star_42", "spr_star_43", "spr_star_44", "spr_star_45",
            "spr_star_46", "spr_star_47", "spr_star_48", "spr_star_49", "spr_star_50"
        };
        iState = STATE_PAUSED; // initial state
        readOptions();
    }

    public void onSurfaceChanged(GL10 gl, int width, int height) {
        gl.glViewport(0, 0, width, height);
        screenWidth = width;
        screenHeight = height;
        screenRatio = (float)width/(float)height;
        
        //set gl parameters
        gl.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        gl.glDisable(GL10.GL_DITHER);
        gl.glHint(GL10.GL_PERSPECTIVE_CORRECTION_HINT, GL10.GL_FASTEST);
        //gl.glEnable(GL10.GL_CULL_FACE); //???? disables sprites
        gl.glShadeModel(GL10.GL_SMOOTH); // Enable Smooth Shading, default not really needed.
        gl.glEnable(GL10.GL_DEPTH_TEST); // Enables depth testing.
        gl.glDepthFunc(GL10.GL_LEQUAL); // The type of depth testing to do.
    	
    	// set font size for screen size
        fFontSize = fBaseFontSize * (float)iScreenDensity / (float)240;
   }

    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        this.gl = gl;
    }

    protected void onPause() {
    	bRendererIsRunning = false;
		iState = STATE_PAUSED;
    }

    protected void onResume() {
    	bRendererIsRunning = true;
		iState = STATE_STARTING;
    }

    //------------------------------------------
    // Startup Functions
    //------------------------------------------

	public void setMapFile (String setMapFile, boolean bUseExtMap, boolean bPlayMusic) {
		// Startup function setting the map base folder
		useExtDir = bUseExtMap;
		sMapFile = setMapFile;
        if(bPlayMusic) {
    		sound.createPlaylist();
    		sound.setRandomPosition();
    		sound.loopPlaylist();
        }
        iState = STATE_STARTING;
	}
	
	private void readOptions() {
        bShowDebug = PreferenceManager.getDefaultSharedPreferences(context).getBoolean("show_debuginfo", false);
        bShowCenter = PreferenceManager.getDefaultSharedPreferences(context).getBoolean("show_center", true);
        bShowRuler = PreferenceManager.getDefaultSharedPreferences(context).getBoolean("show_ruler", true);
	}

 	private void loadFonts() {
		//load system font
        font = new GLText(gl);
		try {
			font.bUseExtDir = false;
			font.LoadFont("ZeroThrees16", gl);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	private void loadMap() {
		iState = STATE_LOADING;
  		
		sprites.loadSprites(gl, sSprites);
		
  		// load universe
		try {
			galaxy = new Galaxy(sMapFile, useExtDir);
        } catch (Exception e) {
			Log.e(this.getClass().getName(), "Universe file could not be loaded: " + sMapFile);
            e.printStackTrace();
			iState = STATE_PAUSED;
            return;			
		}
		mGalaxyView = new GalaxyView(gl, galaxy, sprites);
        mGalaxyView.font = font;
		centerX = mGalaxyView.centerX;
        centerY = mGalaxyView.centerY;
        universeSize = mGalaxyView.universeSize;
        setViewPort();

        //fFontSize = fBaseFontSize * (float)iScreenDensity / (float)240;
        fFontSize = fBaseFontSize * fScreenScale;
		
		// set renderer to running
        iState = STATE_RUNNING;
        bRendererIsRunning = true;        
	}
	
    //------------------------------------------
    // Drawing Loop Functions
    //------------------------------------------
	private void viewOrtho() { // Set Up An Ortho View
		gl.glMatrixMode(GL10.GL_PROJECTION); // Select Projection
		gl.glLoadIdentity(); // Reset The Matrix
		gl.glOrthof(0, screenWidth, 0, screenHeight, -1, 1); // Select Ortho Mode
		gl.glMatrixMode(GL10.GL_MODELVIEW); // Select Modelview Matrix
		gl.glLoadIdentity(); // Reset The Matrix
	}
	
	/*
	private void viewPerspective() // Set Up A Perspective View
	{
	    gl.glEnable(GL10.GL_DEPTH_TEST);
		gl.glMatrixMode(GL10.GL_PROJECTION); // Select Projection
		//gl.glPopMatrix(); // Pop The Matrix
		gl.glMatrixMode(GL10.GL_MODELVIEW); // Select Modelview
		//gl.glPopMatrix(); // Pop The Matrix
		gl.glLoadIdentity(); // Reset The Matrix
	}
	*/

    protected void setViewPort() {
        float tanAngle = (float)Math.tan(Math.PI/6); //pi/8
        camDistZ = 500.0f*universeSize/zoomFactor;
		float maxStarDist = (float)mGalaxyView.systems.sysPos.get(0).z + camDistZ;
		if (zoomFactor<5) {
			viewPortMin.y = centerY + moveY - camDistZ*tanAngle;
        	viewPortMin.x = centerX + moveX - camDistZ*tanAngle*screenRatio;
        	viewPortMax.y = centerY + moveY + camDistZ*tanAngle;
        	viewPortMax.x = centerX + moveX + camDistZ*tanAngle*screenRatio;
		} else {
			// more accurate viewport calculation
			// however heavier on processing
			viewPortMin.y = centerY + moveY - maxStarDist*tanAngle;
			viewPortMin.x = centerX + moveX - maxStarDist*tanAngle*screenRatio;
			viewPortMax.y = centerY + moveY + maxStarDist*tanAngle;
			viewPortMax.x = centerX + moveX + maxStarDist*tanAngle*screenRatio;
		}
		mGalaxyView.viewPortMin = viewPortMin;
        mGalaxyView.viewPortMax = viewPortMax;
		screenLy = (float)(180*(viewPortMax.x-viewPortMin.x)/screenWidth);
    }

	public void navigateTo(Point3D pos) {
		mGalaxyView.setFlag("auto_navigation", true);
		float currX = centerX + moveX;
		float currY = centerY + moveY;
		float deltaX = (float)pos.x - currX;
		float deltaY = (float)pos.y - currY;
		float speed = 0.01f;
		float stepX = deltaX*speed;
		float stepY = deltaY*speed;
		
		boolean bNotArrived = true;
		long lLast;
		long lElapsed;
		while (bNotArrived) {
			lLast = System.currentTimeMillis();
			lElapsed = 0;
			while (lElapsed < 50) {
				lElapsed = System.currentTimeMillis() - lLast;
			}
			deltaX = Math.abs((float)pos.x - (centerX+moveX));
			deltaY = Math.abs((float)pos.y - (centerY+moveY));
			if (deltaX>Math.abs(stepX)) {
				moveX = moveX + stepX;
			}
			if (deltaY>Math.abs(stepY)) {
				moveY = moveY + stepY;
			}
			if (deltaX<Math.abs(2*stepX) & deltaY<Math.abs(2*stepY)) {
				bNotArrived = false;
			}
			setViewPort();			
		}
		mGalaxyView.setFlag("auto_navigation", false);
	}
	
    private void draw3D() {
        //Log.i(this.getClass().getName(), "--draw3D");
        
        if (!bRendererIsRunning) {
            return;
        }
        
		// Update time
        long lNow = System.currentTimeMillis();
        long lFrameElapsed = lNow - lFrameTime;
        lFrameTime = lNow;

        // set camera
        gl.glMatrixMode(GL10.GL_PROJECTION);
        gl.glLoadIdentity();
        // Perspective and aspect ratio of the window
        GLU.gluPerspective(gl, 45.0f, screenRatio, 1.01f, 10000.0f);
        GLU.gluLookAt(gl,
			centerX+moveX, centerY+moveY, -camDistZ,  //eye //-500.0f*universeSize/zoomFactor
			centerX+moveX, centerY+moveY,    0.0f,  //center
			0.0f, -1.0f, 0.0f); //up

        // clear screen
        gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);
	    gl.glEnable(GL10.GL_DEPTH_TEST);
		
        // Now we're ready to draw some 3D objects
        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();

        mGalaxyView.zoomFactor = zoomFactor;
        mGalaxyView.paintComponent();

		// --------------------------------------
        // menu
        // --------------------------------------
		
		viewOrtho();

        //Log.i(this.getClass().getName(), "fScreenScale: " + fScreenScale);

		int iSprSize = (int)(60*fScreenScale);
		sprites.drawSprite(gl, "ui_zoom_in", new float[] {screenWidth-iSprSize, iSprSize, 0}, iSprSize, 1);
		sprites.drawSprite(gl, "ui_zoom_out", new float[] {screenWidth-3*iSprSize, iSprSize, 0}, iSprSize, 1);
		sprites.drawSprite(gl, "ui_menu", new float[] {iSprSize, iSprSize, 0}, iSprSize, 1);
		
		// compass
		if (mGalaxyView.getFlag("show_compass")) {
		    sprites.drawSprite(gl, "ui_compass", new float[] {100*fScreenScale, screenHeight-iSprSize, 0f}, 100*fScreenScale, 1);
		}
		
		// processing indicators
		iSprSize = (int)(16*fScreenScale);
		if (mGalaxyView.bSystemsReady) {
		    sprites.drawSprite(gl, "ui_icon_s", new float[] {140*fScreenScale, 20*fScreenScale, 0f}, iSprSize, 0.5f);
		}
		if (mGalaxyView.bJumpsReady) {
		    sprites.drawSprite(gl, "ui_icon_j", new float[] {180*fScreenScale, 20*fScreenScale, 0f}, iSprSize, 0.5f);
		}
		if (mGalaxyView.getFlag("auto_navigation")) {
		    sprites.drawSprite(gl, "ui_icon_a", new float[] {220*fScreenScale, 20*fScreenScale, 0f}, iSprSize, 0.5f);
		}
        if (mGalaxyView.bPathSelectMode) {
            sprites.drawSprite(gl, "ui_icon_p", new float[] {140*fScreenScale, 60*fScreenScale, 0f}, iSprSize, 0.5f);
        }
		
		// ruler
		if (!bShowMenu & bShowRuler) {
			draw.drawLine(gl, new Point3D(screenWidth-20,100*fScreenScale,0), new Point3D(screenWidth-220*fScreenScale,100*fScreenScale,0), new Color4f(0.6f,0.6f,0.6f,1.0f), 4.0f);
			String sLy =  String.format("%.00f", screenLy)+" ly";				
			if (screenLy <=10) {
				sLy =  String.format("%.01f", screenLy)+" ly";
			}
			draw.drawText(gl, font, sLy, 0.8f*fFontSize, new int[]{screenWidth-(int)(120*fScreenScale),(int)(120*fScreenScale)}, new Color4f(0.6f,0.6f,0.6f,1.0f), GLDraw.TEXT_CENTER, false);		
		}
		
		if (bShowCenter) {
			// center cross
			draw.drawLine(gl, new Point3D(screenWidth/2+2,screenHeight/2,0), new Point3D(screenWidth/2+10,screenHeight/2,0), new Color4f(0.6f,0.6f,0.6f,1.0f), 1.0f);
			draw.drawLine(gl, new Point3D(screenWidth/2-2,screenHeight/2,0), new Point3D(screenWidth/2-10,screenHeight/2,0), new Color4f(0.6f,0.6f,0.6f,1.0f), 1.0f);
			draw.drawLine(gl, new Point3D(screenWidth/2,screenHeight/2+2,0), new Point3D(screenWidth/2,screenHeight/2+10,0), new Color4f(0.6f,0.6f,0.6f,1.0f), 1.0f);
			draw.drawLine(gl, new Point3D(screenWidth/2,screenHeight/2-2,0), new Point3D(screenWidth/2,screenHeight/2-10,0), new Color4f(0.6f,0.6f,0.6f,1.0f), 1.0f);			
		}
		
		if (bShowMenu) {
		    sprites.drawSprite(gl, "ui_quickmenu", new float[] {210*fScreenScale, 265*fScreenScale, 0f}, 420*fScreenScale, 1.0f);
            Color4f colOn = new Color4f(0.2f,0.4f,0.2f,1.0f);
            Color4f colOff = new Color4f(0.2f,0.2f,0.2f,1.0f);
            Color4f col = null;
			// left column
			int posx = (int)(10*fScreenScale);
			if (mGalaxyView.getFlag("show_jump_lines")) { col = colOn; } else { col = colOff; }
            draw.drawText(gl, font, "Jump", fFontSize, new int[] {posx, (int)(380*fScreenScale)}, col);
            draw.drawText(gl, font, "Network", fFontSize, new int[] {posx, (int)(340*fScreenScale)}, col);
            if (mGalaxyView.getFlag("show_no_jumps")) { col = colOn; } else { col = colOff; }
			draw.drawText(gl, font, "Jumpless", fFontSize, new int[] {posx, (int)(270*fScreenScale)}, col);
			draw.drawText(gl, font, "Systems", fFontSize, new int[] {posx, (int)(230*fScreenScale)}, col);
            if (mGalaxyView.getFlag("show_sector_boxes")) { col = colOn; } else { col = colOff; }
			draw.drawText(gl, font, "Sector", fFontSize, new int[] {posx, (int)(160*fScreenScale)}, col);
			draw.drawText(gl, font, "Boxes", fFontSize, new int[] {posx, (int)(120*fScreenScale)}, col);
			// middle column
			posx = (int)(170*fScreenScale);
			if (mGalaxyView.getFlag("show_system_name")) { col = colOn; } else { col = colOff; }
			draw.drawText(gl, font, "System", fFontSize, new int[] {posx, (int)(380*fScreenScale)}, col);
			draw.drawText(gl, font, "Name", fFontSize, new int[] {posx, (int)(340*fScreenScale)}, col);
            if (mGalaxyView.getFlag("show_system_faction")) { col = colOn; } else { col = colOff; }
			draw.drawText(gl, font, "System", fFontSize, new int[] {posx, (int)(270*fScreenScale)}, col);
			draw.drawText(gl, font, "Faction", fFontSize, new int[] {posx, (int)(230*fScreenScale)}, col);
            if (mGalaxyView.getFlag("show_system_sector")) { col = colOn; } else { col = colOff; }
			draw.drawText(gl, font, "System", fFontSize, new int[] {posx, (int)(160*fScreenScale)}, col);
			draw.drawText(gl, font, "Sector", fFontSize, new int[] {posx, (int)(120*fScreenScale)}, col);
			// right column
			posx = (int)(330*fScreenScale);
			if (mGalaxyView.getFlag("show_compass")) { col = colOn; } else { col = colOff; }
			draw.drawText(gl, font, "Show", fFontSize, new int[] {posx, (int)(380*fScreenScale)}, col);
			draw.drawText(gl, font, "Compass", fFontSize, new int[] {posx, (int)(340*fScreenScale)}, col);
            if (mGalaxyView.getFlag("show_homeworlds")) { col = colOn; } else { col = colOff; }
			draw.drawText(gl, font, "Show", fFontSize, new int[] {posx, (int)(270*fScreenScale)}, col);
			draw.drawText(gl, font, "Homeworlds", fFontSize, new int[] {posx, (int)(230*fScreenScale)}, col);
			// find system
			draw.drawText(gl, font, "Find", fFontSize, new int[] {posx, (int)(160*fScreenScale)}, colOff);
			draw.drawText(gl, font, "System", fFontSize, new int[] {posx, (int)(120*fScreenScale)}, colOff);
	    }
		
        // --------------------------------------
        // info
        // --------------------------------------
		
        // date and time
        //drawBackdrop("ui_backdrop", new float[] {-screenRatio+0.035f, 0.0f}, 0.035f, 1.0f);
        String currentTimeString = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date());
        draw.drawText(gl, font, currentTimeString, 0.6f*fFontSize, new int[] {screenWidth-(int)(5*fScreenScale), screenHeight-(int)(25*fScreenScale)}, new Color4f(0.6f,0.6f,0.6f,1.0f), GLDraw.TEXT_RIGHT, false);

        if (bShowDebug) {
		
        	draw.drawText(gl, font, "zoom: " + String.format("%.01f",zoomFactor), 1.5f, new int[] {0,screenHeight-26}, new Color4f(0.6f,0.6f,0.6f,1.0f));
        	draw.drawText(gl, font, "camera distance: " + String.format("%.03f",(-500.0f*universeSize/zoomFactor)), 1.5f, new int[] {0,screenHeight-52}, new Color4f(0.6f,0.6f,0.6f,1.0f));
			draw.drawText(gl, font, "pos: " + String.format("%.02f",(centerX+moveX)) + " " + String.format("%.02f",(centerY+moveY)), 1.5f, new int[] {0,screenHeight-78}, new Color4f(0.6f,0.6f,0.6f,1.0f));
			draw.drawText(gl, font, "universe size: " + String.format("%.02f",universeSize), 1.5f, new int[] {0,screenHeight-104}, new Color4f(0.6f,0.6f,0.6f,1.0f));
        	draw.drawText(gl, font, "viewport min: " + String.format("%.02f",(viewPortMin.x)) + " " + String.format("%.02f",(viewPortMin.y)), 1.5f, new int[] {0,screenHeight-130}, new Color4f(0.6f,0.6f,0.6f,1.0f));
        	draw.drawText(gl, font, "viewport max: " + String.format("%.02f",(viewPortMax.x)) + " " + String.format("%.02f",(viewPortMax.y)), 1.5f, new int[] {0,screenHeight-156}, new Color4f(0.6f,0.6f,0.6f,1.0f));

        	//draw frame rate
	        float fps = 1000 / lFrameElapsed;
	        fLastFrameRate = (199*fLastFrameRate + fps) / 200; // average over last 200 frames
	        draw.drawText(gl, font, "" + java.lang.Math.round(fLastFrameRate) + " fps", 1.5f, new int[] {screenWidth-80,screenHeight-52}, new Color4f(0.6f,0.6f,0.6f,1.0f));
        }
		
	}

    // Default frame function    
    public void onDrawFrame(GL10 gl) {
        //Log.i(this.getClass().getName(), "current state: " + iState);
    	if (iState == STATE_PAUSED) { //iState=0
        	draw3D();
    		return;
    	}
        if (iState == STATE_STARTING) { //iState=1
    		loadFonts();
    		iState = STATE_PRELOADING;
    	}
        if (iState == STATE_PRELOADING) { //iState=2
            gl.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);
			viewOrtho();
			draw.drawText(gl, font, "Loading...", (fFontSize*1.2f), new int[]{screenWidth/2,screenHeight/2}, new Color4f(0.6f,0.8f,1.0f,1.0f), GLDraw.TEXT_CENTER, false);
    		iState = STATE_LOADING;
    		return;
        }
        if (iState == STATE_LOADING) { //iState=3
    		loadMap();
    	}
        if (iState == STATE_RUNNING) { //iState=4
            draw3D();
        }
    }

}
