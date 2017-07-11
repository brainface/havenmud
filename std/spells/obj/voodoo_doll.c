#include <lib.h>
inherit LIB_ITEM;

int charges = 5;
string victim = "";

int SetVictim(string chum);
int SetCharges(int amount);

string GetVictim();
int GetCharges();
int AddCharges(int amount);


int RememberVictim();

static void create() {
   item::create();
   SetKeyName("voodoo doll");
   SetShort("a creepy voodoo doll");
   SetId( ({ "doll" }) );
   SetAdjectives( ({"creepy","voodoo"}) );
   SetLong("A disturbing, crude doll made of clay and dry branches.");
   SetMass(5);
   SetProperty("magic","A cursed creation of the malign mixture of "
     "natural and necromantic magic, this clay doll is used as a focus "
     "for many malicious spells.");
   call_out( (: RememberVictim :), 0 );
}

int RememberVictim() {
  SetVictim(victim);
}

int SetVictim(string chum) {
  if (chum == "") return 0;
  victim = chum;
  SetShort("a creepy voodoo doll of "+capitalize(chum));
  SetLong("A disturbing, crude doll made of clay and dry branches. "
    "Its face bears an eery resemblance to "+capitalize(chum)+".");
  AddSave(({"victim"}));
  return 1;
}

string GetVictim() { return victim;}

int SetCharges(int amount) {
  if (!environment()) return 0;
  if (!environment(environment())) return 0;
  if (amount > 0) charges = amount;
  if (amount <= 0) charges = 0;
  if (charges <= 0) {
    send_messages( ({"crumble"}), "$agent_name%^BOLD%^BLACK%^ "
      "crumbles%^RESET%^ to dust amid the smell of old blood.",
      this_object(),0,environment(environment()));
    call_out( (: eventDestruct :), 0);
  }
  AddSave(({"charges"}));
}

int GetCharges() { return charges; }

int AddCharges(int amount) {
  SetCharges(GetCharges() - amount);
}
