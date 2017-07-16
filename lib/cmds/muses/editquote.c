#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

void ChooseOption(string arg);
void GoToQuote(string arg);
void ConfirmDelete(string arg);
void EditQuote(string arg);
void ConfirmEdit(string confirm, string quote, string author);
int num_quote = 0;

mixed cmd() {
  QUOTES_D->GetQuote((int)num_quote, this_player());
  message("command", 
    "You are on quote " + (string)num_quote + "/" + 
    (string)(QUOTES_D->GetNumQuotes() - 1) + ".\n"
    "[F]orward, [B]ack, [D]elete, [E]dit, [G]oto, [Q]uit", this_player());
  input_to( (: ChooseOption :) );
  return 1;
  }

void ChooseOption(string arg) {
  arg = capitalize(arg);
  switch (arg) {
    case "F" : if ((QUOTES_D->GetNumQuotes() - num_quote) > 1) num_quote += 1;
               cmd();
               break;
    case "B" : if (num_quote) num_quote -= 1;
               cmd();
               break;
    case "D" : message("command", 
                       "Are you sure you want to delete this quote?\n"
                       "[Y]es/[N]o",
                        this_player());
               input_to( (: ConfirmDelete :) );
               break;
    case "E" : message("command", 
                       "Input the new quote in the form, QUOTE~AUTHOR",
                        this_player());
               input_to( (: EditQuote :) );
               break;
    case "G" : message("command", "Input an integer.", this_player());
               input_to( (: GoToQuote :) );
               break;
    case "Q" : break;
    default : message("command", "%^RED%^BOLD%^Invalid Choice!%^RESET%^",
                       this_player());
              cmd();
              break;
    }
  }

void GoToQuote(string arg) {
  int num = to_int(arg);
  if ((num >= 0) && (num < QUOTES_D->GetNumQuotes())) {
    num_quote = num;
    cmd();
    return;
  }
  message("command", 
    "You must input an integer between 0 and " + 
    (string)(QUOTES_D->GetNumQuotes() - 1) + ".", this_player());
  cmd();
  }

void ConfirmDelete(string arg) {
  arg = capitalize(arg);
  if (arg == "Y" || arg == "Yes") {
    QUOTES_D->RemoveQuote(num_quote);
    if (num_quote == QUOTES_D->GetNumQuotes()) num_quote -= 1;
    message("command", "Quote removed.", this_player());
    cmd();
    return;
  }
  cmd();
  }

void EditQuote(string arg) {
  string quote, author;
  if (sscanf(arg, "%s~%s", quote, author)) {
    message("command", "Are you sure you want to edit this quote?\n"
                       "[Y]es/[N]o", this_player());
    input_to( (: ConfirmEdit :), quote, author);
    return;
  }
  message("command", "You made a mistake.  Please try again.", this_player());
  cmd();
  }

void ConfirmEdit(string confirm, string quote, string author) {
  confirm = capitalize(confirm);
  if (confirm == "Y" || confirm == "Yes") {
    QUOTES_D->EditQuote(num_quote, quote, author);
    cmd();
    return;
  }
  cmd();
  }

string GetHelp(string u) {
  return ("Syntax:   \"editquote\"     \n\n"
          "Interactive command for editing quotes.");
  }
