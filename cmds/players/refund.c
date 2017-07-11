#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
  object style;
  object who = this_player();
  int cost;
  foreach(string s in keys(who->GetCombatStyles())) {
    debug(s);
    style = STYLES_D->GetStyle(s);
    if (!style) continue;
    who->AddDevelopmentPoints(cost = style->GetTrainingPointCost());
    CHAT_D->eventSendChannel("Refund", "reports", "Refunded " + who->GetKeyName() + " " + cost + " DP for " + s + ".");
    who->eventPrint("Refunded " + cost + " development points for " + s + ".");
  }
  who->Refund();
  who->SetCombatStyle(0);
  return 1;
}
  
string GetHelp(string u) {
  return "Syntax:   refund \n\n\n"
         "Refunds the original cost of development points spent on old-code combat styles.";
}