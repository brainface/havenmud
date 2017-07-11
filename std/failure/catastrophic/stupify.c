// Thoin@Haven
// stupify failure

#include <lib.h>
#include <daemons.h>
#include <damage_types.h>

inherit LIB_FAILURE;

int eventFail(object who, object spell){
  string spell2;
  int amount = 0;
   
    send_messages(0, "$agent_possessive_noun spell fails causing a "
                     "%^CYAN%^ripple%^RESET%^ of magical energies to slam "
                     "into $agent_name before fading.",who,0,environment(who));
  if (spell->GetSpell()) {
    spell2 = spell->GetSpell();                
    amount = who->GetSpellLevel(spell2);   
    amount = amount-5;
    if (amount < 1) { amount = 1; }
    who->SetSpellBookLevel(spell2,amount);
    } 
  if (spell->GetSong()) {
    spell2 = spell->GetSong();
    amount = who->GetSongLevel(spell2);    
    amount = amount-5;
    if (amount < 1) { amount = 1; }
    who->SetSongBookLevel(spell2,amount);    
    }

  if (playerp(who)) CHAT_D->eventSendChannel("FAILURE!", "reports", who->GetCapName() +
        " got the stupify failure!");
  return 1;
}
