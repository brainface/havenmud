#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;


private string* Brackets = ({
           ({ "", "" }),    // Newbie
                       ({ "%^MAGENTA%^[%^RESET%^", "%^MAGENTA%^]%^RESET%^" }),  // Mortal
                       ({ "%^MAGENTA%^(%^RESET%^", "%^MAGENTA%^)%^RESET%^" }),  // High Mortal
                       ({ "%^MAGENTA%^{%^RESET%^", "%^MAGENTA%^}%^RESET%^" }),  // Legend
                       ({ "%^YELLOW%^|%^RESET%^", "%^YELLOW%^|%^RESET%^" }),  // Avatar
                       ({ "%^BOLD%^RED%^(%^RESET%^", "%^BOLD%^RED%^)%^RESET%^" }),    // Demigod
                       ({ "%^MAGENTA%^<%^RESET%^", "%^MAGENTA%^>%^RESET%^" }),  // Immortal
           ({ "%^BOLD%^MAGENTA%^<%^RESET%^", "%^BOLD%^MAGENTA%^>%^RESET%^" }),  // Immortal     
           ({ "%^BOLD%^BLACK%^(%^RESET%^", "%^BOLD%^BLACK%^)%^RESET%^" }), // Epic
           ({ "%^MAGENTA%^:%^RESET%^", "%^MAGENTA%^:%^RESET%^", }),
                   });

static void create() {
  ::create();
  SetNoClean(1);
}

varargs string AddBrackets(string ch, object who) {
    object ob = who;
    string bc = "%^MAGENTA%^" +ch+ "%^RESET%^"; /* Base Chat Line */
    if (!ob) ob = this_player();

    if (!ob) return (Brackets[1][0] + bc + Brackets[1][1]);
    
    if (duukp(ob)) return "%^GREEN%^{%^RESET%^" + bc + "%^GREEN%^}%^RESET%^";
    if (zaxanp(ob)) return "%^BLUE%^BOLD%^{%^RESET%^" + bc + "%^BLUE%^BOLD%^}%^RESET%^";
    if (laoisep(ob)) return "%^RED%^{%^RESET%^" + bc + "%^RED%^}%^RESET%^";
    if (thoinp(ob)) return "%^BOLD%^BLACK%^{%^RESET%^" + bc + "%^BOLD%^BLACK%^}%^RESET%^";
    if (melchezidekp(ob)) return "%^BOLD%^BLACK%^{%^RESET%^" + bc + "%^BOLD%^BLACK%^}%^RESET%^";
    
    if (adminp(ob))       return (Brackets[7][0] + bc + Brackets[7][1]);
    if (creatorp(ob))     return (Brackets[6][0] + bc + Brackets[6][1]);
    if (epicp(ob))        return (Brackets[8][0] + bc + Brackets[8][1]);
    if (demigodp(ob))     return (Brackets[5][0] + bc + Brackets[5][1]);
    if (avatarp(ob))      return (Brackets[4][0] + bc + Brackets[4][1]);
    if (legendp(ob))      return (Brackets[3][0] + bc + Brackets[3][1]);
    if (high_mortalp(ob)) return (Brackets[2][0] + bc + Brackets[2][1]);
    if (newbiep(ob))      return (Brackets[0][0] + bc + Brackets[0][1]);
    if (!playerp(ob))     return (Brackets[9][0] + bc + Brackets[9][1]);
    /* Default */
    return (Brackets[1][0] + bc + Brackets[1][1]);
}
