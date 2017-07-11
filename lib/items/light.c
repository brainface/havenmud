/*    /lib/light.c
 *    from the Dead Souls V LPC Library
 *    a standard lighting object
 *    created by Descartes of Borg 960512
 *    Version: @(#) light.c 1.2@(#)
 *    Last modified: 96/11/03
 */


private int Lit = 0;
private string LitString = "lit";

// abstract methods
string GetKeyName();
void AddSave(mixed n) {};
string *AddAdjective(string);
string *RemoveAdjective(string);
// end abstract methods

static void create() {
    AddSave(({ "Lit" }));
}

string SetLitString(string lit) { return LitString = lit; }
string GetLitString()           { return LitString;       }

int GetLit() {
    return Lit;
}

static int SetLit(int x) {
    if (x) AddAdjective(LitString);
    if (!x) RemoveAdjective(LitString);
    return (Lit = x);
}

string GetShort() {
    /*  string str;

    if(!(str = item::GetShort()) || str == "") return str;
    return sprintf("%s%s", str, (GetLit() ? " (lit)" : ""));
    */
    if( GetLit() ) return " (" + LitString + ")";
    else return "";
}

mixed CanLight(object who) {
  if (environment() != environment(who) &&  environment() != who)
    return "You don't have that.";
  if( GetLit() ) 
	  return "#It is already lit.";
  return 1;
}

mixed direct_light_obj() {
    return CanLight(this_player());
}

mixed direct_darken_obj() {
	if (GetLit()) { return 1; }
	return "But it is not lit!";
}


mixed eventDarken() {
    object env;
    
  if( env = environment() ) {
	  env->eventPrint("The " + GetKeyName() + " goes dark.");
	  if( living(env) ) {
	    environment(env)->eventPrint(possessive_noun(env) + " " + GetKeyName() + " goes dark.", env);
	    }
   }
   SetLit(0);
   return 1;
}

varargs mixed eventLight(object who, object tool) {
    SetLit(1);
    return 1;
}

