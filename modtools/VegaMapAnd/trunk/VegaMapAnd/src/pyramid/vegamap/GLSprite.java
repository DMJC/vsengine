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
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;

import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.opengl.GLUtils;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

public class GLSprite {

	public boolean useExtDir;
	public String baseDir;
	public int lastBitmapLoaded = -1;

    private final String DIR_IMAGES = "images";

    private Context context;
	private GL10 gl;
    private java.util.HashMap<String, Integer> textureMap; //String=key, Integer=value
	private String[] textureFiles;
	private int[] textureIds;
	private Bitmap[] bitmap;

    // The buffer holding the vertices
    private FloatBuffer vertexBuffer;
    // The buffer holding the texture coordinates
    private FloatBuffer textureBuffer;
    // The buffer holding the indices
    private ByteBuffer indexBuffer;
    // Our texture pointer
    public int[] textures = new int[2];

    // The initial vertex definition
    // Each face is defined, even if indices are available, because
    // of the texturing we want to achieve 
    private float vertices[] = {
        //Vertices according to clockwise faces
        -1.0f,  1.0f, 0.0f, //Vertex v0
        -1.0f, -1.0f, 0.0f, //v0
         1.0f,  1.0f, 0.0f, //v2
         1.0f, -1.0f, 0.0f, //v3
     };
    
     // The initial texture coordinates (u, v)   
     private float texture[] = {          
         //Mapping coordinates for the vertices
         0.0f, 0.0f,
         0.0f, 1.0f,
         1.0f, 0.0f,
         1.0f, 1.0f,
     };
        
     // The initial indices definition   
     private byte indices[] = {
         //Faces definition
         0,1,3, 0,3,2,          //Face front
     };

	public GLSprite(GL10 gl, Context context) {
		this.gl = gl;
		this.context = context;
		reset();
        ByteBuffer byteBuf = ByteBuffer.allocateDirect(vertices.length * 4);
        byteBuf.order(ByteOrder.nativeOrder());
        vertexBuffer = byteBuf.asFloatBuffer();
        vertexBuffer.put(vertices);
        vertexBuffer.position(0);

        byteBuf = ByteBuffer.allocateDirect(texture.length * 4);
        byteBuf.order(ByteOrder.nativeOrder());
        textureBuffer = byteBuf.asFloatBuffer();
        textureBuffer.put(texture);
        textureBuffer.position(0);

        indexBuffer = ByteBuffer.allocateDirect(indices.length);
        indexBuffer.put(indices);
        indexBuffer.position(0);
	}

	public boolean bindTexture(GL10 gl, int textNr) {
		ByteBuffer bb = extract(bitmap[textNr]);
		int width = bitmap[textNr].getWidth();
		int height = bitmap[textNr].getHeight();
		int tex = textureIds[textNr];
		gl.glBindTexture(GL10.GL_TEXTURE_2D, tex); // must be in main gl thread
		gl.glTexImage2D(GL10.GL_TEXTURE_2D, 0, GL10.GL_RGBA, width, height, 0, GL10.GL_RGBA, GL10.GL_UNSIGNED_BYTE, bb);
		gl.glTexParameterx(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_LINEAR);
		gl.glTexParameterx(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_LINEAR);
		bitmap[textNr].recycle();
		return true;
	}

	private Handler mTextureHandler = new Handler() {
		
	    @Override
	    public void handleMessage(Message msg)
	    {
	        Bundle bundle = msg.getData();
	        lastBitmapLoaded = bundle.getInt("lastTextureLoaded");
	        bindTexture(gl, lastBitmapLoaded);
	    }

	};
	
	//http://stackoverflow.com/questions/6318311/threading-textures-load-process-for-android-opengl-game/6319425#6319425
	//http://groups.google.com/group/android-developers/browse_thread/thread/06e00b2ccc8a417b#
	//http://stackoverflow.com/questions/9117288/android-opengl-reloading-textures
	class TextureLoader extends Thread {
	   //private Handler mHandler;
	   //private Bundle mBundle = new Bundle();
	   private int[] tmp_tex;
	   
	   TextureLoader(Handler pHandler, int[] tex) {
	       //mHandler = pHandler;
	       tmp_tex = tex;
	   }

	    @Override
	    public void run() {

	    	// Clear all previous bitmap references to avoid OutOfMemory error.
	    	if (bitmap!=null) {
				for(int i=0; i < bitmap.length; i++) {
					bitmap[i].recycle();
				}
		    	bitmap = null;
	    	}
	    	// Create new bitmaps.
			bitmap = new Bitmap[textureFiles.length];
			textureIds = tmp_tex;
			InputStream is = null;
			String sFileName;
			String extension = ".jpg";

			for(int i=0; i < textureFiles.length; i++) {
		        // Load files from mod dir, except ui icons
				if (useExtDir & !textureFiles[i].substring(0, 2).equals("ui")) {
					
					//http://stackoverflow.com/questions/3912548/android-adb-unable-to-open-sync-connection
					BitmapFactory.Options bfOptions=new BitmapFactory.Options();
				    bfOptions.inDither=false;                     //Disable Dithering mode
				    bfOptions.inPurgeable=true;                   //Tell to gc that whether it needs free memory, the Bitmap can be cleared
				    bfOptions.inInputShareable=true;              //Which kind of reference will be used to recover the Bitmap data after being clear, when it will be used in the future
				    //bfOptions.inTempStorage=new byte[32 * 1024];
				    
					sFileName = baseDir + File.separator + DIR_IMAGES + File.separator + textureFiles[i] + extension;
					FileInputStream fs=null;

					if (new File(sFileName).exists()) {
						try {
					        fs = new FileInputStream(sFileName);
					    } catch (FileNotFoundException e) {
				            Log.e(this.getClass().getName(), "File not found " + sFileName);
					        e.printStackTrace();
					    }
				        try {
				        	if(fs!=null) {
				        		bitmap[i] = BitmapFactory.decodeFileDescriptor(fs.getFD(), null, bfOptions);
				        	}
				        } catch (Exception e) {
			                Log.e(this.getClass().getName(), "Cannot decode bitmap");
							e.printStackTrace();
				        } finally{ 
				            if(fs!=null) {
				                try {
				                    fs.close();
				                } catch (IOException e) {
					                Log.e(this.getClass().getName(), "Error closing file " + sFileName);
				                    e.printStackTrace();
				                }
				            }
				        }

					} else {
			            Log.e(this.getClass().getName(), "Could not load bitmap file " + sFileName);
					}
				} 

		        // Load files from package resources, including ui icons
				if (!useExtDir | textureFiles[i].substring(0, 2).equals("ui")) {
					int textureResource = context.getResources().getIdentifier(textureFiles[i], "drawable", context.getPackageName());
			        is = context.getResources().openRawResource(textureResource);
			        try {
			            //BitmapFactory is an Android graphics utility for images
			            bitmap[i] = BitmapFactory.decodeStream(is);
			        } finally {
			            //Always clear and close
			            try {
			                is.close();
			                is = null;
			            } catch (IOException e) {
			                Log.e(this.getClass().getName(), "bitmap not decoded");
			            }
			        }
				}

				// Get a new texture name and load it up
				textureMap.put(new String(textureFiles[i]), new Integer(i));
				
			    //send the data back to the caller
				lastBitmapLoaded = i;
				
			    //Message msg = Message.obtain();
			    //mBundle.clear();
			    //mBundle.putInt("lastTextureLoaded", i);
			    //msg.setData(mBundle);
			    //mHandler.sendMessage(msg);
				
		    } // for
			
				try {
					this.finalize();
				} catch (Throwable e) {
					e.printStackTrace();
				}
	    } //run

    } // class

	public void loadTextures(int[] tex) {
		TextureLoader mThread = new TextureLoader(mTextureHandler, tex);
	    mThread.start();
	}

	// Set the current texture
	public void setTexture(GL10 gl, String sTextureName)
	{
		int textureid = -1;
		try {
			if (textureIds==null) {
	            Log.e(this.getClass().getName(), "setTexture: textures are null!");
			}
			textureid = textureMap.get(new String(sTextureName)).intValue();
			gl.glBindTexture(GL10.GL_TEXTURE_2D, textureIds[textureid]);
		} catch(Exception e) {
            Log.e(this.getClass().getName(), "setTexture: Error binding texture " + sTextureName);
		}
	}

	// Add texture from resource
	public void add(String sImgName)
	{
		if(textureFiles==null)
		{
			textureFiles = new String[1];
			textureFiles[0] = sImgName;
		}
		else
		{
			String[] newarray = new String[textureFiles.length+1];
			for(int i=0; i < textureFiles.length; i++) {
				newarray[i] = textureFiles[i];
			}
			newarray[textureFiles.length] = sImgName;
			textureFiles = newarray; //x507, x504
		}
	}

	public void reset() {
		textureFiles = null;
		textureIds = null;
		bitmap = null;
		textureMap = new java.util.HashMap<String, Integer>();
	}

	private static ByteBuffer extract(Bitmap bmp)
	{
		ByteBuffer bb = ByteBuffer.allocateDirect(bmp.getHeight() * bmp.getWidth() * 4);
		bb.order(ByteOrder.BIG_ENDIAN);
		IntBuffer ib = bb.asIntBuffer();
		// Convert ARGB -> RGBA
		for (int y = bmp.getHeight() - 1; y > -1; y--)
		{

			for (int x = 0; x < bmp.getWidth(); x++)
			{
				int pix = bmp.getPixel(x, bmp.getHeight() - y - 1);
				int alpha = ((pix >> 24) & 0xFF);
				int red = ((pix >> 16) & 0xFF);
				int green = ((pix >> 8) & 0xFF);
				int blue = ((pix) & 0xFF);

				// Make up alpha for interesting effect
				//ib.put(red << 24 | green << 16 | blue << 8 | ((red + blue + green) / 3));
				ib.put(red << 24 | green << 16 | blue << 8 | alpha);
			}
		}
		bb.position(0);
		return bb;
	}

    // The object own drawing function. Called from the renderer
    // to redraw this instance with possible changes in values.
    public void draw(GL10 gl) {
       //Point to our buffers
       gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
       gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);

       //Enable the vertex and texture state
       gl.glEnable(GL10.GL_TEXTURE_2D);
       gl.glVertexPointer(3, GL10.GL_FLOAT, 0, vertexBuffer);
       gl.glTexCoordPointer(2, GL10.GL_FLOAT, 0, textureBuffer);
       
       //Draw the vertices as triangles, based on the Index Buffer information
       gl.glDrawElements(GL10.GL_TRIANGLES, indices.length, GL10.GL_UNSIGNED_BYTE, indexBuffer);      
       
       //Disable the client state before leaving
       gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
       gl.glDisableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
       gl.glDisable(GL10.GL_TEXTURE_2D);
    }

     // Paint text on the background
    public void paintText(GL10 gl, String sText, float fSizePix, float xPos, float yPos) {
        // xPos, yPos = 0.0 - 1.0
        //indicates the percentage position of the bitmap

        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();

        // Create an empty, mutable bitmap
        Bitmap bitmap = Bitmap.createBitmap(256, 256, Bitmap.Config.ARGB_4444); // POT is everything
        bitmap.eraseColor(Color.TRANSPARENT);
        // get a canvas to paint over the bitmap
        Canvas canvas = new Canvas(bitmap);
        
        // Draw the text
        Paint textPaint = new Paint();
        textPaint.setTextSize(fSizePix);
        textPaint.setAntiAlias(true);
        textPaint.setARGB(0xff, 0xf0, 0xf0, 0xf0);
        canvas.drawText(sText, xPos*256, yPos*256, textPaint);
    
        int[] textures = new int[1];
        //Generate one texture pointer...
        gl.glGenTextures(1, textures, 0);
        //...and bind it to our array
        gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[0]);
    
        //Create Nearest Filtered Texture
        gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_NEAREST);
        gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_LINEAR);
        //Use the Android GLUtils to specify a two-dimensional texture image from our bitmap
        GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bitmap, 0);

        //Clean up
        bitmap.recycle();

        // paint
        gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[0]);
        gl.glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // color of the text blending
        gl.glEnable(GL10.GL_BLEND); //enable transparency blending
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);
        draw(gl); // draw the projection screen canvas
    }

    // Load the textures
    public void loadGLTexture(GL10 gl, Context context, int textureResource) {
        //Get the texture from the Android resource directory
        InputStream is = context.getResources().openRawResource(textureResource);
        Bitmap bitmap = null;
        try {
           //BitmapFactory is an Android graphics utility for images
           bitmap = BitmapFactory.decodeStream(is);

        } finally {
           //Always clear and close
           try {
              is.close();
              is = null;
           } catch (IOException e) {
           }
        }

        //Generate one texture pointer...
        gl.glGenTextures(1, textures, 0);
        //...and bind it to our array
        gl.glBindTexture(GL10.GL_TEXTURE_2D, textures[0]);
        
        //Create Nearest Filtered Texture
        gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MIN_FILTER, GL10.GL_NEAREST);
        gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_MAG_FILTER, GL10.GL_LINEAR);

        //Different possible texture parameters, e.g. GL10.GL_CLAMP_TO_EDGE
        gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_WRAP_S, GL10.GL_REPEAT);
        gl.glTexParameterf(GL10.GL_TEXTURE_2D, GL10.GL_TEXTURE_WRAP_T, GL10.GL_REPEAT);
        
        //Use the Android GLUtils to specify a two-dimensional texture image from our bitmap
        GLUtils.texImage2D(GL10.GL_TEXTURE_2D, 0, bitmap, 0);
        
        //Clean up
        bitmap.recycle();
     }

    public void loadSprites(GL10 gl, String[] sSprites) {
        reset();
        for (int i = 0; i < sSprites.length; i++) {
            add(sSprites[i]);
        }
        //sprites.loadTextures(this.gl);
        lastBitmapLoaded = -1;
        int[] tmp_spr = new int[sSprites.length];
        gl.glGenTextures(sSprites.length, tmp_spr, 0);
        loadTextures(tmp_spr);
        // wait until all sprites are loaded 
        while (lastBitmapLoaded < sSprites.length-1) {
            // do nothing
            //Log.i(this.getClass().getName(), "renderer:lastTextureLoaded: " + sprites.lastTextureLoaded);
        }
        for (int i = 0; i < sSprites.length; i++) {
            bindTexture(gl, i);
        }
    }

    public void drawSprite(GL10 gl, String spriteName, Point3D point, float fScale, float fAlpha) {
        drawSprite(gl, spriteName, new float[] {(float)point.getX(), (float)point.getY(), (float)point.getZ()}, fScale, fAlpha);
    }
    
    public void drawSprite(GL10 gl, String spriteName, float fPosition[], float fScale, float fAlpha) {
        //Log.i(this.getClass().getName(), "--drawSprite");
        //Log.i(this.getClass().getName(), "loading sprite: " + spriteName);
        // x=0, y=0: center of sprite, center of screen
        // max = screenHeight/(screenHeight/2) or screenWidth
        // x =  screenRatio: bottom of screen  y =  1: left of the screen
        // x = -screenRatio: top of screen     y = -1: right of screen
     
        setTexture(gl, spriteName);
     
        gl.glLoadIdentity();
     
        gl.glEnable(GL10.GL_TEXTURE_2D);
        gl.glColor4f(1.0f, 1.0f, 1.0f, fAlpha);
        gl.glEnable(GL10.GL_BLEND);
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);
     
        gl.glTranslatef(fPosition[0], fPosition[1], fPosition[2]);
        gl.glScalef(fScale, fScale, fScale);
        draw(gl);
        gl.glDisable(GL10.GL_TEXTURE_2D);
         
    }
    
    public void drawBackdrop(GL10 gl, String spriteName, float fPosition[], float fScale[], float fAlpha) {
        // x=0, y=0: center of sprite, center of screen
        // max = screenHeight/(screenHeight/2) or screenWidth
        // x =  screenRatio: bottom of screen  y =  1: left of the screen
        // x = -screenRatio: top of screen     y = -1: right of screen
        
        setTexture(gl, spriteName);
        
        gl.glLoadIdentity(); //reset the current model view matrix
        
        gl.glColor4f(1.0f, 1.0f, 1.0f, fAlpha);
        gl.glEnable(GL10.GL_BLEND); //enable transparency blending
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);
        
        gl.glTranslatef(fPosition[0], fPosition[1], 0.0f);
        gl.glScalef(fScale[0], fScale[1], 1.0f);
        draw(gl); // draw the projection screen canvas
    }

}
