/*
 * CampaignXmlIO.java
 *
 * Created on 31 July 2005, 16:25
 *
 * To change this template, choose Tools | Options and locate the template under
 * the Source Creation and Management node. Right-click the template and choose
 * Open. You can then make changes to the template in the Source Editor.
 */

package campaigneditor;

import java.io.File;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Result;
import javax.xml.transform.Source;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import org.w3c.dom.Document;
import org.xml.sax.SAXParseException;

/**
 *
 * @author Daniel Aleksandrow
 */
public class CampaignXmlIO {
    
    public static Document readXmlFile(File input)
    {
        DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
        factory.setValidating(false);
        
        try {
            System.out.print("Opening Campaign Store.");
            DocumentBuilder builder = factory.newDocumentBuilder();
            Document config = builder.parse(input);
            return config;
        } catch (SAXParseException err) {
            System.out.println("\n\n Error during parsing"
                    + ",line " + err.getLineNumber());
            System.out.println("    " + err.getMessage());  
            Exception exc = err;
            if (err.getException() != null)
                exc = err.getException();
            exc.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
    
    public static Document readXmlFile(String file)
    {
        try
        {
            File input = new File(file);
            return CampaignXmlIO.readXmlFile(input);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
    
    public static void writeXmlFile(Document doc, String filename)
    {
        try
        {
            File input = new File(filename);
            CampaignXmlIO.writeXmlFile(doc, input);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return;
    }
    
    public static void writeXmlFile(Document doc, File file)
    {
        try {
            Source source = new DOMSource(doc);

            Result result = new StreamResult(file);

            Transformer xformer = TransformerFactory.newInstance().newTransformer();
            xformer.transform(source, result);
        } catch (Exception e) {
            System.out.println("An error occured while writing the campaign:");
            System.out.println(e.getMessage());
            System.out.println(e.getStackTrace().toString());
        }
    }
}
