package swing.src.swing;

import java.io.*;
import java.net.*;

public class Client {
    private Socket sock;
    private BufferedReader input;
    private BufferedWriter output;

    ///
    /// Initialise la connexion.
    /// Renvoie une exception en cas d'erreur.
    ///
    public Client(String host, int port) throws UnknownHostException, IOException {
        try {
            sock = new java.net.Socket(host, port);
        } catch (java.net.UnknownHostException e) {
            System.err.println("Client: Couldn't find host " + host + ":" + port);
            throw e;
        } catch (java.io.IOException e) {
            System.err.println("Client: Couldn't reach host " + host + ":" + port);
            throw e;
        }

        try {
            input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
        } catch (java.io.IOException e) {
            System.err.println("Client: Couldn't open input or output streams");
            throw e;
        }
    }

    ///
    /// Envoie une requete au server et retourne sa reponse.
    /// Noter que la methode bloque si le serveur ne repond pas.
    ///
    public String send(String request) {
        /**Envoyer la requete au serveur*/
        try {
            request += "\n"; // ajouter le separateur de lignes
            output.write(request, 0, request.length());
            output.flush();
        } catch (java.io.IOException e) {
            System.err.println("Client: Couldn't send message: " + e);
            return null;
        }

        /**Recuperer le resultat envoye par le serveur*/
        try {
            return input.readLine();
        } catch (java.io.IOException e) {
            System.err.println("Client: Couldn't receive message: " + e);
            return null;
        }
    }
}