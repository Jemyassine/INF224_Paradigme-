package swing.src;

import swing.src.swing.Client;
import swing.src.swing.Window;

public class Main {
    public static void main(String[] args) {
        String host = "localhost";
        int port = 3331;

        if (args.length >= 1) host = args[0];
        if (args.length >= 2) port = Integer.parseInt(args[1]);

        try {
            Client client = new Client(host, port);
            Window.setClient(client);
            new Window();
            System.out.println("Client connected to " + host + ":" + port);
        } catch (Exception e) {
            System.err.println("Client: Couldn't connect to " + host + ":" + port);
            System.exit(1);
        }
    }
}