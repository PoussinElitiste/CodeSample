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
   if (sck == INVALID_SOCKET)
      exit (erreur("Création"));
   return sck;
}

void FermerSocket (const socket_t sck)
{
   shutdown (sck, SD_BOTH);
   closesocket (sck);
}

void Connecter
   (socket_t sck, const string &adresse, const short port)
{
   sockaddr_in dest = { 0 };
   dest.sin_family= AF_INET;
   dest.sin_addr.s_addr=
      inet_addr (adresse.c_str ());
   dest.sin_port = port;
   socket_operation_t resultat = connect
      (sck, reinterpret_cast<const sockaddr*> (&dest),
            sizeof (sockaddr));
   if (EstErreur (resultat))
      exit (erreur ("Connexion"));
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

int main ()
{
   const string ADRESSE_DU_SERVEUR = "127.0.0.1";
   const short PORT_DU_SERVEUR = htons(4321);
   const string MESSAGE = "Ça marche!";
   const char DELIMITEUR_FIN = '#';
   // Initialisation des sockets pour le client
   ChargerSockets ();
   // Obtention du socket client
   socket_t socketClient = CreerSocket ();
   // Tentative de connexion au serveur
   Connecter (socketClient, ADRESSE_DU_SERVEUR, PORT_DU_SERVEUR);
   // Envoi du message "Ça marche!"
   Envoyer (socketClient, MESSAGE, DELIMITEUR_FIN);
   // Affichage des résultats de l'envoi
   cout << "Envoi réussi de " << MESSAGE.length () + 1
        << " octets, délimiteur inclus. Message: \""
        << MESSAGE << '\"' << endl;
   // Réception de la réponse du serveur
   string Recu = Recevoir (socketClient, DELIMITEUR_FIN);
   // Affichage des résultats de la réception
   cout << "Réception réussie de " << Recu.length () + 1
        << " octets, délimiteur inclus. Message reçu: \""
        << Recu << '\"' << endl;
   // Fermeture du socket et nettoyage
   FermerSocket (socketClient);
   DechargerSockets ();
}
