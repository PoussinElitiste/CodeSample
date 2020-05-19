#include <winsock2.h>
#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <string>
using std::string;

typedef SOCKET socket_t;
bool EstInvalide (const socket_t sck)
   { return sck == INVALID_SOCKET; }
typedef int socket_operation_t;
bool EstErreur (const socket_operation_t op)
   { return op == SOCKET_ERROR; }

int erreur (const string &msg)
{
   const int code = ::WSAGetLastError();
   cerr << msg << "; erreur " << code << endl;
   return code;
}

void ChargerSockets ()
{
   const long VERSION_DEMANDEE = MAKEWORD(2,2);
   WSAData configWinsock;
   if (::WSAStartup (VERSION_DEMANDEE, &configWinsock) != 0)
      exit (erreur("Démarrage"));
}

void DechargerSockets ()
   { ::WSACleanup (); }

socket_t CreerSocket ()
{
   socket_t sck =
      socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if (EstInvalide (sck))
      exit (erreur("Création"));
   return sck;
}

void ReserverPort (const socket_t sck, const short port)
{
   sockaddr_in Nom = { 0 };
   Nom.sin_family = AF_INET;
   Nom.sin_port = port;
   socket_operation_t resultat = bind
      (sck, reinterpret_cast<const sockaddr*> (&Nom),
            sizeof (sockaddr_in));
   if (EstErreur (resultat))
   {
      cerr << "Port " << htons(port) << ", ";
      exit (erreur ("Obtention"));
   }
   // Créer la file d’attente pour demandes de connexion
   int TailleFileAttente = 16; // arbitraire
   if (EstErreur (listen (sck, TailleFileAttente)))
      exit (erreur ("Créer file d'attente"));
}

socket_t AccepterClient (const socket_t srv)
{
   sockaddr_in Homologue = { 0 };
   int tailleHomologue= sizeof (sockaddr);
   socket_t sck =
      accept (srv, reinterpret_cast<sockaddr *>(&Homologue),
              &tailleHomologue);
   if (EstInvalide (sck))
      exit (erreur ("Accepter connexion"));
   return sck;
}

string Recevoir (const socket_t sck, const char FIN)
{
   const int TAILLE_TAMPON = 64; // arbitraire
   char Tampon[TAILLE_TAMPON];
   string MessageRecu;
   bool ReceptionCompletee = false;
   do
   {
      socket_operation_t n =
         recv (sck, Tampon, TAILLE_TAMPON, 0);
      if (EstErreur (n))
         exit (erreur ("Réception"));
      MessageRecu.append (Tampon, Tampon + n);
      if (Tampon[n-1] == FIN)
         ReceptionCompletee = true;
   }
   while (!ReceptionCompletee);
   return MessageRecu.substr (0, MessageRecu.length()-1);
}

void Envoyer (const socket_t sck, string Msg, const char FIN)
{
   Msg += FIN;
   while (!Msg.empty ())
   {
      socket_operation_t PlusRecent =
         send(sck, Msg.c_str(), static_cast<int>(Msg.length ()), 0);
      if (EstErreur (PlusRecent))
         exit (erreur ("Envoi"));
      Msg = Msg.substr (PlusRecent);
   }
}

void FermerSocket (const socket_t sck)
{
   shutdown (sck, SD_BOTH);
   closesocket (sck);
}


int main ()
{
   const short PORT_A_RESERVER= htons(4321);
   const string MESSAGE = "Reçu 5 sur 5";
   const char DELIMITEUR_FIN = '#';
   // Initialisation des sockets pour le serveur
   ChargerSockets ();
   // Obtention du socket serveur
   socket_t socketServeur = CreerSocket ();
   // On rend le serveur disponible en réservant son port
   ReserverPort (socketServeur, PORT_A_RESERVER);
   // Acceptation du client
   socket_t pourJaser = AccepterClient (socketServeur);
   // Réception du message du client
   string Recu = Recevoir (pourJaser, DELIMITEUR_FIN);
   // Affichage des résultats de la réception
   cout << "Réception réussie de " << Recu.length () + 1
        << " octets, délimiteur inclus. Message reçu: \""
        << Recu << '\"' << endl;
   // Envoi du message "Reçu 5 sur 5"
   Envoyer (pourJaser, MESSAGE, DELIMITEUR_FIN);
   // Affichage des résultats de l'envoi
   cout << "Envoi réussi de " << MESSAGE.length () + 1
        << " octets, délimiteur inclus. Message: \""
        << MESSAGE << '\"' << endl;
   // Fermeture des sockets
   FermerSocket (pourJaser);
   FermerSocket (socketServeur);
   DechargerSockets ();
}
