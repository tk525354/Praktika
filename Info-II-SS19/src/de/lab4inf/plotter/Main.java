/*
 * Project: Info-II-SS19
 *
 * Copyright (c) 2008-2019,  Prof. Dr. Nikolaus Wulff
 * University of Applied Sciences, Muenster, Germany
 * Lab for computer sciences (Lab4Inf).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
package de.lab4inf.plotter;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.WindowConstants;
import javax.swing.border.BevelBorder;

/**
 * Basic skeleton for a Swing based GUI application.
 *
 * @author nwulff
 * @since 02.04.2013
 * @version $Id: Main.java,v 1.2 2019/04/02 12:58:54 nwulff Exp $
 */
public class Main {
    private JFrame frame;
    protected JPanel canvas;
    private JPanel statusBar;
    protected JTextField status;

    /**
     * Public default constructor.
     */
    public Main() {
        initialize();
    }

    /**
     * Start of the application.
     * 
     * @param args command line arguments
     */
    public static void main(String[] args) {
        Main app = new Main();
        app.start();
    }

    /**
     * Initialize the application.
     */
    protected void initialize() {
        frame = new JFrame(" -- plotter example -- ");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setBounds(50, 50, 50 + 640, 50 + 480);
        frame.setJMenuBar(createMenuBar());

        frame.getContentPane().add(createStatusBar(), BorderLayout.SOUTH);
        frame.getContentPane().add(createContent(), BorderLayout.CENTER);
    }

    /**
     * Start the graphical user interface.
     */
    public void start() {
        // show the GUI
        frame.setVisible(true);
        status.setText("Application started");
    }

    /**
     * Internal helper to create the main content.
     * 
     * @return component with application content.
     */
    protected JComponent createContent() {
        canvas = new JPanel();
        canvas.addMouseListener(new Painter());
        canvas.setBackground(Color.WHITE);
        canvas.setForeground(Color.RED);
        canvas.setBorder(new BevelBorder(BevelBorder.LOWERED));
        return canvas;
    }

    /**
     * Internal helper to create the statusbar and -fields.
     * 
     * @return component with status/bar.
     */
    protected JComponent createStatusBar() {
        FlowLayout layout = new FlowLayout(FlowLayout.LEFT);
        layout.setHgap(5);

        statusBar = new JPanel(layout);
        statusBar.add(new JLabel("Status: "));

        status = new JTextField();
        status.setPreferredSize(new Dimension(400, 0));
        status.setEditable(false);
        status.setBorder(new BevelBorder(BevelBorder.RAISED, Color.MAGENTA, Color.LIGHT_GRAY));
        status.getInsets().set(2, 10, 2, 10);
        statusBar.add(status);

        return statusBar;
    }

    /**
     * Internal helper to create the frames menubar.
     * 
     * @return menu bar
     */
    protected JMenuBar createMenuBar() {
        JMenuBar mb = new JMenuBar();
        JMenuItem item;
        JMenu menu;
        // Action menu
        menu = new JMenu("Actions");
        mb.add(menu);
        item = new JMenuItem("Draw RandomCircle");
        item.addActionListener(new RandomDrawer());
        menu.add(item);

        item = new JMenuItem("Draw RandomRectangle");
        item.addActionListener(new RandomDrawer());
        menu.add(item);
        
        menu.addSeparator();
        item = new JMenuItem("Exit");
        item.addActionListener(new AppCloser());
        menu.add(item);

        // Color menu not used so far
        menu = new JMenu("Colors");
        mb.add(menu);
        
        item = new JMenuItem("Black");
        item.addActionListener(new ChangePaint());
        menu.add(item);
        
        item = new JMenuItem("Red");
        item.addActionListener(new ChangePaint());
        menu.add(item);
        
        item = new JMenuItem("Blue");
        item.addActionListener(new ChangePaint());
        menu.add(item);
        
        item = new JMenuItem("Green");
        item.addActionListener(new ChangePaint());
        menu.add(item);
        
        // Help menu not used so far
        menu = new JMenu("Help");
        mb.add(menu);

        return mb;
    }

    class ChangePaint implements ActionListener {
    	
    	
    	public void actionPerformed(ActionEvent e) {
    	String command = e.getActionCommand();
    	
    	if(command.equals("Black")) {
    		canvas.setForeground(Color.BLACK);
    	}else if(command.equals("Red")) {
    		canvas.setForeground(Color.RED);
    	}else if(command.equals("Blue")) {
    		canvas.setForeground(Color.BLUE);
    	}else if(command.equals("Green")) {
    		canvas.setForeground(Color.GREEN);
    	}
    		
    	}
    	
    }
    
    class AppCloser implements ActionListener {
        /*
         * (non-Javadoc)
         * 
         * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            System.out.printf("application finished, bye-bye... \n");
            frame.setVisible(false);
            frame.dispose();
            System.exit(0);
        }
    }

    class RandomDrawer implements ActionListener {
        /*
         * (non-Javadoc)
         * 
         * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
         */
        @Override
        public void actionPerformed(ActionEvent e) {
            String command = e.getActionCommand();
            System.out.printf(command);
        	int width = canvas.getWidth();
            int height = canvas.getHeight();
            double x = Math.random();
            double y = Math.random();
            double r = Math.random();
            String msg = String.format("rnd draw x:%.3f y:%.3f r:%.3f", x, y, r);
            status.setText(msg);
            x = width * x;
            y = height * y;
            r = r * Math.sqrt(width * height);
            System.out.println(msg);
            Graphics2D gc = (Graphics2D) canvas.getGraphics();
            Color tmp = gc.getColor();

            if (command.equals("Draw RandomCircle")) {
                gc.setColor(canvas.getForeground());
                gc.drawOval((int) x, (int) y, (int) r, (int) r);
                gc.setColor(tmp);
            } else if (command.equals("Draw RandomRectangle")) {
                gc.setColor(canvas.getForeground());
                gc.drawRect((int) x, (int) y, (int) r, (int) r);
                gc.setColor(tmp);
            }
        }
    }

    class Painter extends MouseAdapter {
        Point start, end;

        /*
         * (non-Javadoc)
         * 
         * @see java.awt.event.MouseListener#mousePressed(java.awt.event.MouseEvent)
         */
        @Override
        public void mousePressed(MouseEvent e) {
            start = e.getPoint();
            String msg = String.format("Mouse start: %d,%d ", start.x, start.y);
            status.setText(msg);
            System.out.println(msg);
        }

        /*
         * (non-Javadoc)
         * 
         * @see java.awt.event.MouseListener#mouseReleased(java.awt.event.MouseEvent)
         */
        @Override
        public void mouseReleased(MouseEvent e) {
            end = e.getPoint();
            String msg = String.format("Mouse end: %s", end);
            status.setText(msg);
            System.out.println(msg);
            Graphics gc = canvas.getGraphics();
            Color tmp = gc.getColor();
            gc.setColor(e.getComponent().getForeground());
            gc.drawLine(start.x, start.y, end.x, end.y);
            gc.setColor(tmp);
            
        }
    }
}
