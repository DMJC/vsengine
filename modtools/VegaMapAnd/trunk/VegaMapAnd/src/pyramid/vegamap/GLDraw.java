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

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;

import javax.microedition.khronos.opengles.GL10;

public class GLDraw {

    public static final int TEXT_LEFT = 0;
    public static final int TEXT_CENTER = 1;
    public static final int TEXT_RIGHT = 2;

    private FloatBuffer lineCoordsFBuffer;

    public GLDraw() {
    }

    protected static FloatBuffer makeFloatBuffer(float[] arr) {
        ByteBuffer bb = ByteBuffer.allocateDirect(arr.length * 4);
        bb.order(ByteOrder.nativeOrder());
        FloatBuffer fb = bb.asFloatBuffer();
        fb.put(arr);
        fb.position(0);
        return fb;
    }
 
    protected static IntBuffer makeIntBuffer(int[] arr) {
        ByteBuffer vbb = ByteBuffer.allocateDirect(arr.length * 4);
        vbb.order(ByteOrder.nativeOrder());
        IntBuffer texBuffer = vbb.asIntBuffer();
        texBuffer.put(arr);
        texBuffer.position(0);
        return texBuffer;
    }
    
    private void initVertices(float[] pos1, float[] pos2, float thickness) {
		double angle = Math.PI/4 + Math.atan((pos2[1]-pos1[1])/(pos2[0]-pos1[0]));
		float dx = (float)Math.cos(angle)*thickness/2;
		float dy = (float)Math.sin(angle)*thickness/2;
		
        float[] lineCoordsF = {
    		pos1[0]+dx,  pos1[1]+dy, pos1[2],
    		pos1[0]-dx,  pos1[1]-dy, pos1[2],
    		pos2[0]+dx,  pos2[1]+dy, pos2[2],
    		pos2[0]-dx,  pos2[1]-dy, pos2[2]
        };
        lineCoordsFBuffer = makeFloatBuffer(lineCoordsF);
    }

    public void drawLine(GL10 gl, Point3D pos1, Point3D pos2, Color4f colorRGBA) {
		drawLine(gl, pos1, pos2, colorRGBA, 1);
	}
	
    public void drawLine(GL10 gl, Point3D pos1, Point3D pos2, Color4f colorRGBA, float width) {
        float[] lineCoordsF = {
			(float)pos1.x,  (float)pos1.y, (float)pos1.z,
			(float)pos2.x,  (float)pos2.y, (float)pos2.z
			};
        lineCoordsFBuffer = makeFloatBuffer(lineCoordsF);

        gl.glDisable(GL10.GL_TEXTURE_2D);
        gl.glLoadIdentity();
        gl.glColor4f(colorRGBA.r, colorRGBA.g, colorRGBA.b, colorRGBA.a);
        gl.glLineWidth(width);
        gl.glVertexPointer(3, GL10.GL_FLOAT, 0, lineCoordsFBuffer);
        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
        gl.glDrawArrays(GL10.GL_LINES, 0, 2);
        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
    }
 
    public void drawBeam(GL10 gl, float[] pos1, float[] pos2, float thickness) {
        initVertices(pos1, pos2, thickness);
        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
        gl.glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        gl.glVertexPointer(3, GL10.GL_FLOAT, 0, lineCoordsFBuffer);
        gl.glPushMatrix();
        gl.glTranslatef(0.0f, 0.0f, 0.0f);
        gl.glDrawArrays(GL10.GL_TRIANGLE_STRIP, 0, 4);
        gl.glPopMatrix();
        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
    }

    //------------------------------------------
    // Text Support Functions
    //------------------------------------------

    /*
    private void drawBackdrop(GL10 gl, String spriteName, float fPosition[], float fScale[], float fAlpha) {
        // x=0, y=0: center of sprite, center of screen
        // max = screenHeight/(screenHeight/2) or screenWidth
        // x =  screenRatio: bottom of screen  y =  1: left of the screen
        // x = -screenRatio: top of screen     y = -1: right of screen
        
        //gl.glDisable(GL10.GL_BLEND); //disable transparency blending
        sprites.setTexture(gl, spriteName);
        
        gl.glLoadIdentity(); //reset the current model view matrix
        
        gl.glColor4f(1.0f, 1.0f, 1.0f, fAlpha);
        gl.glEnable(GL10.GL_BLEND); //enable transparency blending
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);
        
        gl.glTranslatef(fPosition[0], fPosition[1], 0.0f);
        gl.glScalef(fScale[0], fScale[1], 1.0f);
        background.draw(gl); // draw the projection screen canvas
        
    }
    */
   
    public String[] breakText(GLText font, String sText, float fSize, int iWidth) {
        
        font.SetScale(fSize);
        int len = font.GetTextLength(sText);
        int nrlines = (int)java.lang.Math.round((double)(iWidth/2+len)/iWidth);
        String lines[] = new String[nrlines];
        boolean bNewLine = false;
        
        String words[] = sText.split(" ");
        int linenr = 0;
        for (int i=0; i<words.length; i++) {
            bNewLine = false;
            if (words[i] != null & words[i].length() > 2) {
                if (words[i].substring(words[i].length()-2).equals("\\n")) {
                    words[i] = words[i].substring(0, words[i].length()-2);
                    bNewLine = true;
                }
            }
            // create a new line
            if (!(lines[linenr]==null)) {
                if (font.GetTextLength(lines[linenr] + words[i] + " ") > iWidth ) {
                    linenr += 1;
                }
            }
            if (lines[linenr]==null) {
                lines[linenr] = words[i] + " ";
            } else {
                lines[linenr] += words[i] + " ";
            }
            // create a new empty line, except for last word
            if (bNewLine & i!=words.length-1) {
                linenr += 1;
            }
        } // for i
        
        return lines;
    }
    
    //------------------------------------------
    // 2D Text Functions
    //------------------------------------------

	public void drawText(GL10 gl, GLText font, String sText, float fSize, int[] pos, Color4f color) {
		drawText(gl, font, sText, fSize, pos, color, TEXT_LEFT, false);
	}
	
	public void drawText(GL10 gl, GLText font, String sText, float fSize, int[] pos, Color4f color, int iMode, boolean bDrawBackdrop) {
	    gl.glMatrixMode(GL10.GL_MODELVIEW);
	    gl.glLoadIdentity();
	    gl.glEnable(GL10.GL_BLEND);
	    gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);	    
		
		font.SetScale(fSize);
		font.SetPolyColor(color.r, color.g, color.b, color.a);
		if (iMode==TEXT_LEFT) {
	    	font.SetCursor(pos[0], pos[1]);
		}
		if (iMode==TEXT_CENTER) {
			int hei = font.GetTextHeight();
			int len = font.GetTextLength(sText);
			if (bDrawBackdrop) {
				//drawBackdrop("ui_backdrop", new float[] {screenWidth/2, aPosition[1]+totalHei/2}, new float[] {screenWidth, totalHei}, 1.0f);
			}
	    	font.SetCursor(pos[0]-len/2, pos[1]-hei/2);
		}
		if (iMode==TEXT_RIGHT) {
			int len = font.GetTextLength(sText);
			if (bDrawBackdrop) {
				//drawBackdrop("ui_backdrop", new float[] {screenWidth/2, aPosition[1]+totalHei/2}, new float[] {screenWidth, totalHei}, 1.0f);
			}
	    	font.SetCursor(pos[0]-len, pos[1]);
		}
		font.Print(gl, sText);
	}     

    //------------------------------------------
    // 3D Text Functions
    //------------------------------------------

	public void drawText(GL10 gl, GLText font, String sText, float fSize, Point3D position) {
		drawText(gl, font, sText, fSize, position, new Color4f(1.0f,1.0f,1.0f, 1.0f), TEXT_LEFT, false);
	}
	
	public void drawText(GL10 gl, GLText font, String sText, float fSize, Point3D position, Color4f  color) {
		drawText(gl, font, sText, fSize, position, color, TEXT_LEFT, false);
	}

	public void drawText(GL10 gl, GLText font, String sText, float fSize, Point3D position, Color4f  color, int iMode) {
		drawText(gl, font, sText, fSize, position, color, iMode, false);
	}
	
	public void drawText(GL10 gl, GLText font, String sText, float fSize, Point3D pos, Color4f color, int iMode, boolean bDrawBackdrop) {
	    gl.glMatrixMode(GL10.GL_MODELVIEW);
	    gl.glLoadIdentity();
	    gl.glEnable(GL10.GL_BLEND);
	    gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);	    

		if (iMode==TEXT_LEFT) {
			font.print3D(gl, sText, pos, fSize, color);
		}
		if (iMode==TEXT_CENTER) {
			int hei = font.GetTextHeight();
			int len = font.GetTextLength(sText);
			if (bDrawBackdrop) {
				//drawBackdrop("ui_backdrop", new float[] {screenWidth/2, aPosition[1]+totalHei/2}, new float[] {screenWidth, totalHei}, 1.0f);
			}
			font.print3D(gl, sText, new Point3D(pos.x-len/2,pos.y-hei/2,pos.z), fSize, color);
		}
		if (iMode==TEXT_RIGHT) {
			int len = font.GetTextLength(sText);
			if (bDrawBackdrop) {
				//drawBackdrop("ui_backdrop", new float[] {screenWidth/2, aPosition[1]+totalHei/2}, new float[] {screenWidth, totalHei}, 1.0f);
			}
			font.print3D(gl, sText, new Point3D(pos.x-len,pos.y,pos.z), fSize, color);
		}
	    
	}     

    public void printParagraph(GL10 gl, GLText font, String sText, float fSize, Point3D position, Color4f color, int iMode, boolean bDrawBackdrop) {
        // this function is kind'a unfinished work-in-progress
        // yPos: 0 - at the bottom; height - at the top
        if (position==null) {
            position = new Point3D(0,0,0);
        }
        
        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();
        // Multi-coloured fonts on the fly are achieved by using the cursor to maintain the text position
        // and changing the polygon colour for each new block of text.   
        gl.glEnable(GL10.GL_BLEND);
        gl.glBlendFunc(GL10.GL_SRC_ALPHA, GL10.GL_ONE_MINUS_SRC_ALPHA);     
        font.SetScale(fSize);
        font.SetPolyColor(color.r, color.g, color.b, color.a);
        
        int hei = font.GetTextHeight();
        int len = 0;
        String lines[] = new String[] {sText};
        int totalHei = hei*lines.length;
        int margin = totalHei/2;
        // draw backdrop
        // screenHeight-8-(hei*lines.length)/2 = -480 - 8
        // text position to sprite coord
        // h=480 -> x = -0.6
        // h=0   -> x =  0.6
        // x = ratio * (-(h-h/2)/(h/2))
        //float y_txtcoord = screenHeight-8-(hei*lines.length)/2;
        //float y_txtcoord = screenHeight-8-margin-(hei*lines.length)/2;
        //float y_spr_coord = (float) (screenRatio * -(y_txtcoord-0.5*(float)screenHeight)/(0.5*(float)screenHeight));
        //Log.i(this.getClass().getName(), "y_txtcoord = " + y_txtcoord);
        //Log.i(this.getClass().getName(), "y_spr_coord " + y_spr_coord);
        // text size to sprite size
        // h = 480 -> s = 0.6;
        // size = screenRatio * h / screenHeight
        // size = screenH * screenRatio * h/screenH
        //float ysize_txtcoord = (16+hei*lines.length);
        //float ysize_sprcoord = (ysize_txtcoord*screenRatio/screenHeight);
        //Log.i(this.getClass().getName(), "ysize_txtcoord = " + ysize_txtcoord);
        //Log.i(this.getClass().getName(), "ysize_sprcoord " + ysize_sprcoord);
        
        if (iMode==TEXT_LEFT) {
            if (bDrawBackdrop) {
                //drawBackdrop("ui_backdrop", new float[] {screenWidth/2, aPosition[1]+totalHei/2}, new float[] {screenWidth, totalHei}, 1.0f);
            }
            font.print3D(gl, sText, position, fSize, color);
        }
        if (iMode==TEXT_CENTER) {
            if (bDrawBackdrop) {
                //drawBackdrop("ui_backdrop", new float[] {screenWidth/2, aPosition[1]+totalHei/2}, new float[] {screenWidth, totalHei}, 1.0f);
            }
            for (int i=0; i<lines.length; i++) {
                len = font.GetTextLength(lines[i]);
                font.print3D(gl, sText, new Point3D(position.x-len/2,position.y+margin-8-hei*(i+1),position.z), fSize, color);
            }
        }
        if (iMode==TEXT_RIGHT) {
            if (bDrawBackdrop) {
                //drawBackdrop("ui_backdrop", new float[] {screenWidth/2, aPosition[1]+totalHei/2}, new float[] {screenWidth, totalHei}, 1.0f);
            }
            font.print3D(gl, sText, position, fSize, color);
        }
        
        gl.glEnable(GL10.GL_BLEND);
        gl.glBlendFunc(GL10.GL_ONE, GL10.GL_ONE);
    }

}
