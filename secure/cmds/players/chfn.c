/*    /secure/cmds/player/chfn.c
 *    from the Foundation II LPC Library
 *    just when you thought you were safe from lisp
 *    created by Descartes of Borg 950517
 */

#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

static void eventGeneratePassword(string);

mixed cmd(string args) {
    function f;
    string rname;

    message("system", "Changing user information for " + (string)previous_object()->GetCapName() + ": ", previous_object());
    rname = (string)previous_object()->GetRealName();
    message("prompt", "Real name [" + rname + "] ", previous_object());
    f = function(string str, string old, object ob) {
	function g;

	if( !str || str == "" ) str = old;
	if( str != old ) {
	    ob->SetRealName(str);
	    ob->SetOOCName(capitalize(str));
	    message("system", "Real name changed to " + str, ob);
	}
	else message("system", "Real name unchanged.", ob);
	str = (string)ob->GetEmail();
	CHARACTER_D->eventUnlink(str, this_player()->GetKeyName());
	message("prompt", "Email [" + str + "] ", ob);
	g = function(string str, string old, object ob) {
	    function h;
	    
	    if( !str || str == "" ) str = old;
	    if( str != old ) {
		string a, b;

		if( sscanf(str, "%s@%s", a, b) != 2 ) {
		    message("system", "Invalid email.", ob);
		    return;
		}
		ob->SetEmail(str);
		CHARACTER_D->eventLink(str, this_player()->GetKeyName());
		message("system", "Email changed to " + str, ob);
//		eventGeneratePassword(str); /* removed until I can figure out the mailing system -- Melchezidek 2013-12-11 */
	  }
	  else {
	    message("system", "Email unchanged.", ob);
	  }

	};
	input_to(g, 0, str, ob);
    };
    input_to(f, "" + rname, previous_object());
    return 1;
}

string GetHelp(string u) {
    return "Syntax: <chfn>\n\n"
	         "Allows you to change your real life information.\n\n"
	         "See also: passwd";
}

static void eventGeneratePassword(string email) {
  string word = translate("password", 0, "unused");
  string pass;
  this_player()->SetPassword(pass = crypt(word, 0));
  this_player()->SetConfirmedEmail(1);
  this_player()->eventPrint(
    "An email has been sent to " + email + " with a new password "
    "for this character. This allows us to verify the email address! "
    "Hotmail and Yahoo accounts should watch their \"junk\" folders, "
    "as this email is often flagged incorrectly as spam. It is strongly "
    "recommended that you NOT use a hotmail account for Haven."
    );
  SMTP_D->eventCreateOutgoingMessage( ({ email }),
     "Thank you for updating! (Password enclosed!)",
     "Your character named " + capitalize(this_player()->GetKeyName()) + 
     " has been confirmed!\n"
     "Your password has been set to: \"" + word + "\", and you should \n"
     "use the command \"passwd\" to change this as soon as you login. \n"
     "Please visit our forum at http://havenmud.com/forum.htm for game updates! \n"
     "Thank you for confirming your email with us, \n"
     "Duuk@Haven!\n"
     );
   CHARACTER_D->eventLink(email, this_player()->GetKeyName());
}
