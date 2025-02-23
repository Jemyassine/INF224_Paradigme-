package swing.src.swing;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.Color;

/**Java Swing Components*/
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import javax.swing.JMenuBar;
import javax.swing.JToolBar;
import javax.swing.JMenu;
import javax.swing.JTextField;
import javax.swing.JMenuItem;



public class Window extends JFrame implements ActionListener {
    private static final long serialVersionUID = 1L; /**Cette variable est réclamée par le compilateur pour préciser la version de la classe*/
    private JTextArea textArea;
    private JButton button1, button2, btnExit, btnClear, btnAddVideo, btnRemove;
    private JMenuBar menuBar;
    private JMenu menu;
    private JToolBar toolBar, toolBar2;
    private JTextField textField, fileNameTextField, pathTextField, field3, field4;
    private JMenuItem multimedia, group;

    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;
    static String host = DEFAULT_HOST;
    static int port = DEFAULT_PORT;
    private static Client client = null;

    public Window() {
        setLayout(new BorderLayout());
        textArea = new JTextArea(10, 30);
        textArea.setBackground(Color.white);

        /**Ajouter des ascenseurs à un JTextArea*/
        JScrollPane scrollableTextArea = new JScrollPane(this.textArea);
        scrollableTextArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        scrollableTextArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

        add(scrollableTextArea, BorderLayout.CENTER);

        /**Insertion des boutons dans l'interface*/
        button1 = new JButton("Play");
        button1.addActionListener(this);
        button1.setBackground(Color.BLUE.darker());
        button1.setForeground(Color.BLACK);

        button2 = new JButton("Show");
        button2.addActionListener(this);
        button2.setBackground(Color.BLUE.darker());
        button2.setForeground(Color.BLACK);

        btnExit = new JButton("Exit");
        btnExit.addActionListener(this);
        btnExit.setBackground(Color.BLUE.darker());
        btnExit.setForeground(Color.BLACK);

        btnAddVideo = new JButton("Add Media");
        btnAddVideo.addActionListener(this);
        btnAddVideo.setBackground(Color.BLUE.darker());
        btnAddVideo.setForeground(Color.BLACK);

        btnRemove = new JButton("Remove");
        btnRemove.addActionListener(this);
        btnRemove.setBackground(Color.BLUE.darker());
        btnRemove.setForeground(Color.BLACK);

        btnClear = new JButton("Clear");
        btnClear.addActionListener(this);
        add(btnClear, BorderLayout.EAST);
        btnClear.setBackground(Color.BLUE.darker());
        btnClear.setForeground(Color.BLACK);

        /**Champs de saisie de texte*/
        textField = new JTextField();
        textField.setBackground(Color.GREEN);

        fileNameTextField = new JTextField();
        fileNameTextField.setBackground(Color.GREEN);

        pathTextField = new JTextField();
        pathTextField.setBackground(Color.GRAY);

        field3 = new JTextField();
        field3.setBackground(Color.GREEN);

        field4 = new JTextField();
        field4.setBackground(Color.GREEN);

        /**Menu liste en haut à gauche*/
        menuBar = new JMenuBar();
        menu = new JMenu("List");
        menuBar.add(menu);
        setJMenuBar(menuBar);

        multimedia = new JMenuItem("Multimedia");
        multimedia.addActionListener(this);
        menu.add(multimedia);

        group = new JMenuItem("Groups");
        group.addActionListener(this);
        menu.add(group);

        /**Barre d'outils supérieure*/
        toolBar = new JToolBar();
        toolBar.add(textField);
        toolBar.add(button1);
        toolBar.add(button2);
        toolBar.add(btnRemove);
        toolBar.add(btnExit);
        add(toolBar, BorderLayout.NORTH);

        /**Barre d'outils inférieure*/
        toolBar2 = new JToolBar();
        toolBar2.add(fileNameTextField);
        toolBar2.add(pathTextField);
        toolBar2.add(field3);
        toolBar2.add(field4);
        toolBar2.add(btnAddVideo);
        add(toolBar2, BorderLayout.SOUTH);
        
        /**Méthodes de JFrame*/
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setTitle("STP Alaf"); // set-top box Alaf
        pack(); // calcul récursif des positions et des tailles
        setVisible(true); // fait apparaître la fenêtre
    }

    public static void setClient(Client client) {
        Window.client = client;
    }

    /**Actions selon le protocole défini*/
    private String getResponse(String text) {
        String output = "";
        String[] txt = text.split("ç;1");
        for (String txt_i : txt)
            output += txt_i + "\n";
        return output;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == btnClear) {
            textArea.setText("");
            textField.setText("");
            fileNameTextField.setText("");
            pathTextField.setText("");
            field3.setText("");
            field4.setText("");
        } else if (e.getSource() == btnExit) {
            System.exit(0);
        } else {
            String txt = textField.getText();
            String command = null;

            if (e.getSource() == group) {
                command = "lGrp";
            } else if (e.getSource() == multimedia) {
                command = "lMlt";
            } else if (e.getSource() == button1) {
                command = "play " + txt;
            } else if (e.getSource() == button2) {
                command = "find " + txt;
            } else if (e.getSource() == btnRemove) {
                command = "remv " + txt;
            } else if (e.getSource() == btnAddVideo) {
                String str = field4.getText();
                if (str.length() > 0)
                    command = "addP " + fileNameTextField.getText() + " " + pathTextField.getText() + " " + field3.getText() + " "
                            + field4.getText();
                else
                    command = "addV " + fileNameTextField.getText() + " " + pathTextField.getText() + " " + field3.getText();
            }

            System.out.print("Request: " + command + "\n");
            try {
                String response = client.send(command);
                response = getResponse(response);
                System.out.println("Response:\n" + response);
                textArea.append(response);
            } catch (Exception excp) {
                System.err.println("Client: error");
                return;
            }
        }
    }
}