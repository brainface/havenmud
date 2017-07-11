
#include <lib.h>
#include <daemons.h>
#include "include/guild.h"

private static class GuildClass Guild;
private int isWelcomed;

int eventDestruct();

static void create() {
  Guild = new(class GuildClass);
  Guild->leader = 0;
  Guild->name = 0;
  Guild->objectName = 0;
  Guild->skill = ({});
  Guild->MagicGuild = 0;
  isWelcomed = 0;
}

static void init() {
  if(!present(this_object(), this_player())) return;
  if((string)this_player()->GetGuild() != (string)GetGuildName()) return;
  if (GetMagicGuild()) this_player()->AddChannel(GetGuildName());
  this_player()->AddChannel(GetGuildName());
  if((string)this_player()->GetKeyName() == (string)GetLeader()) {
    if (GetMagicGuild())
    add_action((:eventBring:), "bring");
    add_action((:eventInitiate:), "initiate");
    add_action((:eventRetire:), "retire");
    this_player()->eventPrint("%^YELLOW%^As Guild Leader, you may <initiate>, <retire>, or <bring> members.%^RESET%^");
  }
  this_player()->eventPrint("\n");
  if(!isWelcomed) {
    eventWelcome(this_player());
    isWelcomed = 1;
  }
}

mixed CanJoin(object ob) { return 1; }

string SetLeader(string str) {
  if(!stringp(Guild->leader)) Guild->leader = str;
  return Guild->leader;
}

string GetLeader() { return Guild->leader; }

string SetGuildName(string str) {
  if(!stringp(Guild->name)) Guild->name = str;
  return Guild->name;
}

string GetGuildName() { return Guild->name; }

string SetGuildObject(string str) {
  if(!stringp(Guild->objectName)) Guild->objectName = str;
  return Guild->objectName;
}

string GetGuildObject() { return Guild->objectName; }

int eventBring(string str) {
  object who;

  if(!str) return notify_fail("Bring whom?\n");
  who = find_player(lower_case(str));
  if (!who) {
    message("system",
      (capitalize(str)) + " is no where to be found.\n", this_player() );
  return 1;
 }
  if((string)who->GetGuild() != (string)GetGuildName())
    return notify_fail(who->GetName() + " is not one of you!\n");
  if(   environment(who)->GetProperty("no teleport")
     || environment(this_player())->GetProperty("no teleport")
     || environment(this_player())->GetProperty("no magic"))
    return notify_fail("A magic force blocks your powers.\n");
  if(present(who, environment(this_player())))
    return notify_fail(capitalize(str) + " is here.\n");
  if((int)this_player()->GetMagicPoints() < 150)
    return notify_fail("Too low on magic power.\n");
  this_player()->AddMagicPoints(-150);
  who->eventPrint("%^CYAN%^Your guild leader summons you.%^RESET%^");
  who->eventMoveLiving(environment(this_player()));
  if(!present(who, environment(this_player())))
    this_player()->eventPrint("%^CYAN%^" + capitalize(str)
      + " is beyond your reach.%^RESET%^");
  return 1;
}

int eventInitiate(string str) {
  object initiate;
  object guildObject;
  int amt;
  mixed ret;

  amt = (this_player()->GetMaxMagicPoints())/2;
  if(!str) return notify_fail("Initiate whom?\n");
  initiate = present(lower_case(str), environment(this_player()));
  if(!initiate || !living(initiate))
    return notify_fail("No one of that nature here.\n");
  if(stringp(ret = CanJoin(initiate))) return notify_fail(ret);
  else if(!ret) return ret;
  if((int)this_player()->GetMagicPoints() < amt)
    return notify_fail("Too low on magic power.\n");
  if(initiate->GetGuild())
    return notify_fail("You may only initiate people without guild "
      + "affiliation.\n");
  initiate->SetGuild((string)GetGuildName());
  if(guildObject = new((string)GetGuildObject()))
    guildObject->eventMove(initiate);
  this_player()->AddMagicPoints(-amt);
  CHAT_D->eventSendChannel("GUILD", "reports", capitalize(initiate->GetKeyName()) + " has joined the " +
                           GetGuildName() + " guild.");

  eventJoin(initiate);
  return 1;
}

void eventJoin(object ob) {
  ob->eventPrint("%^YELLOW%^You are now a member of the "
    + pluralize((string)GetGuildName()) + ".%^RESET%^");
  environment(ob)->eventPrint("%^YELLOW%^" +(string)ob->GetName()
    + " is now a member of the "
    + pluralize((string)GetGuildName()) + ".%^RESET%^", ob);
}

int eventRetire(string str) {
  object retiree;
  object guildObject;

  if(!str) return notify_fail("Retire whom?\n");
  retiree = present(lower_case(str), environment(this_player()));
  if(!retiree || !living(retiree))
    return notify_fail("No one of that nature here.\n");
  if((string)retiree->GetGuild() != (string)GetGuildName())
    return notify_fail(retiree->GetName() + " is not one of us!\n");
  guildObject = present(GetGuildName() + "_guild_object", retiree);
  if(!guildObject) error("Problem with guild object.");
  guildObject->eventDestruct();
  retiree->SetGuild(0);
  CHAT_D->eventSendChannel("GUILD", "reports", capitalize(retiree->GetKeyName()) + " has been retired from the " +
                           GetGuildName() + " guild.");
  eventUnjoin(retiree);
  return 1;
}

void eventUnjoin(object ob) {
  ob->eventPrint("%^RED%^You are no longer a member of the "
    + pluralize((string)GetGuildName()) + ".%^RESET%^");
  environment(ob)->eventPrint("%^RED%^" + (string)ob->GetName()
    + " is no longer a member of the "
    + pluralize((string)GetGuildName()) + ".%^RESET%^", ob);
  ob->RemoveChannel(GetGuildName());
}

void eventWelcome(object ob) {
  message("system",
    "%^YELLOW%^Welcome, " + GetGuildName() + " Guild member!",
     ob);
}


int SetMagicGuild(int x) { return (Guild->MagicGuild = x); }

int GetMagicGuild() { return (Guild->MagicGuild); }
