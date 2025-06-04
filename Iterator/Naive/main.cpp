#include "Client.h"

int main()
{
    Client client;
    
    Facebook fb;
    Instagram ig;
    TikTok tiktok;
    
    client.sendFacebookMessage(fb); 
    client.sendInstagramMessage(ig); 
    client.sendTikTokMessage(tiktok);    
    return 0;
}
