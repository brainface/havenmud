/* /lib/combatmsg.c
 * Haven lib version
 * Alpha version: 3/20/2007
 * Duuk
 */
string GetMeleeAttackString();
string *GetWords(int);

varargs void SendCombatMessages(object target, int x, object weapon, string limb) {
   string attack_string = GetMeleeAttackString();
   string *words;
   if( !limb ) limb = "body";
   if (weapon) attack_string = weapon->GetKeyName();
   if( x == -2 ) {
     send_messages( ({ "miss" }),
       "$agent_name $agent_verb $target_name.",
       this_object(), target, environment());
     return;
   }
   if( x == -1 ) {
     send_messages( ({ "dodge" }),
       "$agent_name $agent_verb $target_possessive_noun attack.",
       target, this_object(), environment());
     return;
   }
   words = GetWords(x);
   send_messages( ({ words[0] }),
     "$agent_name $agent_verb $target_name " + (words[1] ? words[1] + " " : "" ) + "in the " + limb + " with $agent_possessive " + attack_string + ".",
     this_object(), target, environment() );
   return;
}

string *GetWords(int x) {
  switch (x) {
   case 0:
      return ({ "hit", "ineffectively" });
      break;
   case 1..50:
    return ({ "hit", "%^BOLD%^GREEN%^softly%^RESET%^" });
    break;
   case 51..100:
    return ({ "hit", "%^GREEN%^hard%^RESET%^" });
    break;
   case 101..200:
    return ({ "hit", "%^BOLD%^BLUE%^really hard%^RESET%^" });
    break;
   case 201..400:
    return ({ "smash", "%^BLUE%^brutally%^RESET%^" });
    break;
   case 401..600:
    return ({ "crush", "%^BOLD%^RED%^severely%^RESET%^" });
    break;
   case 601..800:
    return ({ "pulverize", "%^RED%^forcibly%^RESET%^" });
    break;
   case 1000..1000000:
    return ({ "destroy", "%^RED%^utterly%^RESET%^" });
    break;
   default:
    return ({ "hit", 0 });
    break;
  }
}

