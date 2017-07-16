#include <lib.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("spammerblinker");
   SetShort("spammerblinker");
   SetId( ({ "spammer","blinker","bl","spammerblinker" }) );
}

void init() {
   ::init();
   add_action("spamblink","spamblink");
}

int spamblink(string args) {
   object who;
   string lineth;
   int lines;
   int i=0;
   int x=0;
   string whob;
   string printme = "";
   string spamword = "SAB";
   string array color = ({ "","%^BLUE%^","%^GREEN%^","%^YELLOW%^","%^WHITE%^","%^BLACK%^",
                           "%^ORANGE%^","%^RED%^","%^MAGENTA%^","%^CYAN%^",
                           "%^ORANGE%^","%^MAGENTA%^" });
   string array bcolor = ({ "","%^B_BLUE%^","%^B_GREEN%^","%^B_YELLOW%^","%^B_WHITE%^",
                            "%^B_BLACK%^","%^B_ORANGE%^","%^B_RED%^","%^B_MAGENTA%^",
                            "%^B_BLACK%^","%^B_BLACK%^","%^B_CYAN%^" });
   if(!args) return 0;
   if(args == "") return 0;
   sscanf(args,"%s %s",whob,lineth);
   if(!whob || !lineth) return 0;
   if(!find_user(whob)) return 0;
   who = find_user("sabrielle");
   lines = to_int(lineth);
   for(i=0;i<lines;i++) {
      for(x=0;x<17;x++) {
         printme += "" + color[random(12)] + bcolor[random(12)] +
                    spamword + "";
      }
      printme += "\n";
      x = 0;
   }
   who->eventPrint("%^FLASH%^%^BOLD%^" + printme + "%^RESET%^");
   return 1;
}

