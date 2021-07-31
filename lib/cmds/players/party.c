#include <lib.h>
#include <daemons.h>

mixed cmd(string args) {
  object who, target;
  string party_member;
  string action;
  string *tmp = ({ });
  
  who = this_player();
  tmp = who->GetPartyMembers();
  if (!args) {
    who->eventPrint("<party add>, <party remove>, <party allow>, or <party leave>");
    if (sizeof(tmp)) {
      foreach(string i in tmp) { tmp -= ({ i }); tmp += ({ capitalize(i) }); }
      who->eventPrint("You are currently in a party with " + conjunction(tmp, "and") + ".");
    }
    return 1;
  }
  if (args == "leave") {
    CHAT_D->eventSendChannel("PARTY", "reports", who->GetKeyName() + " left a party with " + conjunction(who->GetPartyMembers() + ({ who->GetKeyName() }), "and"));
    foreach(string person in who->GetPartyMembers()) {
      who->RemovePartyMember(person);
      if (find_player(person)) find_player(person)->RemovePartyMember(who->GetKeyName());
    }
    who->eventPrint("You have left your party.");
    return 1;
  }
  if (sscanf(args, "%s %s", action, party_member) != 2) {
    who->eventPrint("You can <party add> <party remove> <party allow> or <party leave>.");
    if (sizeof(tmp)) {
      foreach(string i in tmp) { tmp -= ({ i }); tmp += ({ capitalize(i) }); }
      who->eventPrint("You are currently in a party with " + conjunction(tmp, "and") + ".");
    }
    return 1;
  }
  if (!target = find_player(party_member = lower_case(party_member))) {
    who->eventPrint("Cannot find " + capitalize(party_member) + "!");
    return 1;
  }
  switch(action) {
    case "add":
      if (target->GetProperty("party_allow_" + who->GetKeyName())) {
        target->RemoveProperty("party_allow_" + who->GetKeyName());
        if (0/*(target->GetLevel()  > who->GetLevel() * 1.3) || (target->GetLevel() < who->GetLevel() * 0.7) && (who->GetLevel() < 100 || target->GetLevel() < 100) && (who->GetLevel() + target->GetLevel() > 30)*/) {
          who->eventPrint("In order to party, you must be within 30% of the level of the leader.");
          return 1;
        }
        CHAT_D->eventSendChannel("PARTY", "reports", target->GetKeyName() + " joined a party with " + conjunction(who->GetPartyMembers() + ({ who->GetKeyName() }), "and"));
        target->AddPartyMember(who->GetKeyName());
        foreach(string person in who->GetPartyMembers()) {
          if (find_player(person)) {
            find_player(person)->AddPartyMember(target->GetKeyName());
            target->AddPartyMember(person);
          }
        }
        who->AddPartyMember(target->GetKeyName());
      } else {
        who->eventPrint("That person needs to <party allow> your name first.");
      }
      break;
    case "remove":      
      CHAT_D->eventSendChannel("PARTY", "reports", who->GetKeyName() + " kicked " + target->GetKeyName() + " from a party with " + conjunction(who->GetPartyMembers() + ({ who->GetKeyName() }), "and"));
      target->RemovePartyMember(who->GetKeyName());
      foreach(string person in who->GetPartyMembers()) {
        if (find_player(person)) {
          find_player(person)->RemovePartyMember(target->GetKeyName());
          target->RemovePartyMember(person);
        }
      }
      who->RemovePartyMember(target->GetKeyName());
      break;
    case "leave":
        CHAT_D->eventSendChannel("PARTY", "reports", target->GetKeyName() + " left a party with " + conjunction(who->GetPartyMembers() + ({ who->GetKeyName() }), "and"));
        foreach(string person in who->GetPartyMembers()) {
          who->RemovePartyMember(person);
          if (find_player(person)) find_player(person)->RemovePartyMember(who->GetKeyName());
        }
      break;
    case "allow":
      who->SetProperty("party_allow_" + party_member, 1);
      who->eventPrint("You are willing to party with " + capitalize(party_member) + ".");
      break;
    default:
      who->eventPrint("party add, party remove, party allow, or party leave?");
      break;
    }
    return 1;
} 

string GetHelp(string u) {
  return "Syntax: \n\n"
         "<party allow PERSON> : Allows that person to add you to a party. \n"
         "<party add PERSON>   : Allows a leader to add a person to a party. \n"
         "<party remove PERSON>: Kicks a person from a party. \n"
         "<party leave>        : Quits a party.\n"
         "<party>              : Shows help and displays current party members.\n";
}
