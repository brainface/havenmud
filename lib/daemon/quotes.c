/*  The quotes daemon.
 *  Duuk
 */
#include <lib.h>
#include <save.h>
#include <message_class.h>
inherit LIB_DAEMON;

class quote {
   string Quote;
   string Author;
   string Contributor;
  }

private class quote *Quotes = ({ });

static void create() {
  daemon::create();
  SetNoClean(1);
  restore_object(SAVE_QUOTES);
  }

class quote *AddQuote(string quote, string author, string contrib) {
  class quote NewQuote;
   NewQuote = new(class quote);
  if (!quote) return 0;
  if (!author) return 0;
  if (!contrib) return 0;
  NewQuote->Quote = quote;
  NewQuote->Author = author;
  NewQuote->Contributor = contrib;
  Quotes += ({ NewQuote });
  unguarded( (: save_object, SAVE_QUOTES :) );
  return Quotes;
  }

int eventDisplayQuote(object who) {
  class quote this_quote = Quotes[random(sizeof(Quotes))];
  who->eventPrint("\"" + this_quote->Quote + "\" ~ " + this_quote->Author, MSG_SYSTEM);
  return 1;
  }

int GetNumQuotes() {
  return sizeof(Quotes);
  }

int GetQuote(int num, object who) {
  class quote this_quote = Quotes[num];
  message("system", 
    "\"" + this_quote->Quote + "\" ~ " + this_quote->Author + " ~ " + 
    capitalize(this_quote->Contributor), who);
  return 1;
  }

int RemoveQuote(int num) {
  Quotes -= ({ Quotes[num] });
  unguarded( (: save_object, SAVE_QUOTES :) );
  return 1;
  }

int EditQuote(int num, string quote, string author) {
  if (quote) Quotes[num]->Quote = quote;
  if (author) Quotes[num]->Author = author;
  unguarded( (: save_object, SAVE_QUOTES :) );
  return 1;
  }
