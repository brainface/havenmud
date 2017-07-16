#include <lib.h>
#include <daemons.h>
inherit LIB_NPC;

int eventAdvanceStatClass(object who, string stat);
int eventAdvanceStatLevel(object who, string stat);
string LocalCurrency;

static void create() {
  ::create();
}

string SetLocalCurrency(string x) { 
  return LocalCurrency = x;
}

string GetLocalCurrency() {
  if (!LocalCurrency) 
    return CURRENCY_D->GetTownCurrency(GetTown());
  return LocalCurrency;
}

void eventGreet(object who) {
  eventRequest(who, 0);
}

mixed eventAsk(object who, string args) {
  string what, stat, style;
  if (!userp(who)) {
    who->eventDie(this_object());
    return 1;
  }
  if (!args) {
    eventForce("speak I'm really not sure what you want. Do you want me to "
               "<train STAT level> or <train STAT class>?");
    return 1;
  }
  if (sscanf(args, "%s %s %s", what, stat, style) != 3) {
    eventForce("speak I'm really not sure what you want. Do you want me to "
               "<train STAT level> or <train STAT class>?");
    return 1;
  }
  if (what != "train") {
    eventForce("speak I'm really not sure what you want. Do you want me to "
               "<train STAT level> or <train STAT class>?");
    return 1;
  }
  if (style == "level") {
    return eventAdvanceStatLevel(who, stat);
  }
  if (style == "class") {
    return eventAdvanceStatClass(who, stat);
  }
  eventForce("speak I'm really not sure what you want. Do you want me to "
             "<train STAT level> or <train STAT class>?");
  return 1;
}

int eventAdvanceStatClass(object who, string stat) {
  string *stats = who->GetStats();
  string *istats = who->GetImprovedStats();
  int cost, c_class;
  if (member_array(stat, stats) == -1) {
    eventForce("speak Your development has greater needs if you believe I can advance your " + stat + "!");
    return 1;
  }
  if (member_array(stat, istats) != -1) {
    eventForce("speak Your " + stat + " has already been improved. I can help you no more.");
    return 1;
  }
  cost = 10000 * currency_rate(GetLocalCurrency());
  if (who->GetCurrency(GetLocalCurrency()) < cost) {
    eventForce("speak Although I would like to aid you, you must pay a slight toll of " + cost +
               " " + GetLocalCurrency() + " for me to aid you along your path.");
    return 1;
  }
  if (who->GetDevelopmentPoints() < 40) {
    eventForce("speak I would like to help you, " + capitalize(who->GetKeyName()) + " but you need " 
               "more development before we can speak.");
    who->eventPrint("You need 40 development points to perform that action.");
    return 1;
  }
  if ((c_class = who->GetStatClass(stat)) == 1) {
    eventForce("speak You can advance that part of you no further.");
    return 1;
  }
  who->AddCurrency(GetLocalCurrency(), -cost);
  who->AddDevelopmentPoints(-40);
  who->SetStat(stat, who->GetBaseStatLevel(stat), (c_class - 1));
  eventForce("speak You have been trained in the fine arts of " + stat + ".");
  who->AddImprovedStat(stat);
  CHAT_D->eventSendChannel(GetCapName(), "reports", who->GetCapName() + " has advanced " + stat + 
                           " to class " + (c_class - 1) + ".");
  return 1;
}

int eventAdvanceStatLevel(object who, string stat) {
    string *stats = who->GetStats();
  string *istats = who->GetImprovedStats();
  int cost, c_class;
  if (member_array(stat, stats) == -1) {
    eventForce("speak Your development has greater needs if you believe I can advance your " + stat + "!");
    return 1;
  }
  cost = 2500 * currency_rate(GetLocalCurrency());
  if (who->GetCurrency(GetLocalCurrency()) < cost) {
    eventForce("speak Although I would like to aid you, you must pay a slight toll of " + cost +
               " " + GetLocalCurrency() + " for me to aid you along your path.");
    return 1;
  }
  if (who->GetDevelopmentPoints() < 1) {
    eventForce("speak I would like to help you, " + capitalize(who->GetKeyName()) + " but you need " 
               "more development before we can speak.");
    who->eventPrint("You need 1 development point to perform that action.");
    return 1;
  }
  if ((c_class = who->GetBaseStatLevel(stat)) >= 125) {
    eventForce("speak You can advance your " + stat + " no further.");
    return 1;
  }
  who->AddCurrency(GetLocalCurrency(), -cost);
  who->AddDevelopmentPoints(-1);
  who->SetStat(stat, who->GetBaseStatLevel(stat) + 1, who->GetStatClass(stat));
  eventForce("speak You have been trained in the fine arts of " + stat + ".");
  CHAT_D->eventSendChannel(GetCapName(), "reports", who->GetCapName() + " has advanced " + stat + 
                           " to " + who->GetBaseStatLevel(stat) + ".");
  return 1;
}

mixed eventRequest(object who, string args) {
  eventForce("speak I'm really not sure what you want. Do you want me to "
             "<train STAT level> or <train STAT class>?");
  return 1;
}
 
