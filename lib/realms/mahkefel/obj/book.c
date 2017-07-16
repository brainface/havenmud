/*
 * book.c
 * A player-writeable book
 * once a book is titled, only the author
 * can write more in it.
 * (to prevent vandalism)
 * Mahkefel jan 2011
 */
#include <lib.h>
#include <vendor_types.h>
#include <daemons.h>
inherit LIB_ITEM;

private string title = "";
private string author = "";
private string authorFullName = "";
private mapping pages = ([ ]);

void SetupBook();
mapping GetPages();
string GetAuthor();

static void create() {
  item::create();
  SetKeyName("book");
  SetMaterials( ({ "wood" }) );
  AddSave( ({ "title", "author", "authorFullName", "pages" }) );
  SetId( ({ "book" }) );
  SetAdjectives( ({ "small","leather-bound" }) );
  SetDamagePoints(300);
  SetMass(20);
  SetVendorType(VT_TREASURE);
  SetShort( "A book" );
  SetLong( "It's a long story");
  SetRead( "default", "The book is several pages long. "
    "Perhaps you should <read page 1 on book>?" );
  foreach (int page in ({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20})) {
    SetRead("page " + page,"The page is blank.");
  }
  SetValue(100);
  call_out( (: SetupBook :), 0);
}

// handles writing in a book
// 'write' isn't really a verb, we are using 'use'
// for everything. this leads to some convoluted sentances
mixed eventUse(object me, string args) {
  string entry1, entry2, entry3 = "";
  int pageNo = 0;

  // once a book is 'titled', it has an author. only the author can
  // write/edit a book.
  if (author != "" && me->GetKeyName() != author) {
    me->eventPrint("You are not the author of this book, and cannot add to it!");
    return 0;
  }

  sscanf(args, "write on %s %s", entry1, entry2);
  if (entry1 == "cover") {
    if (strlen(entry2) > 30) {
      title = entry2[0..29];
    } else {
      title = entry2;
    }
    CHAT_D->eventSendChannel("Book", "reports",
      capitalize(this_player()->GetKeyName()) +
      " titled a book: " + title);
    // name only (for player identification)
    author = me->GetKeyName();
    // name + titles (for fancy covers)
    authorFullName = me->GetName();
  } else if (entry1 == "page") {
    if (author == "") {
      me->eventPrint("You should title the book first!");
      return 0;
    }
    sscanf(entry2, "%s %s", entry2, entry3);
    pageNo = to_int(entry2);
    // pages can't be negative/0
    if (pageNo <= 0) { 
      me->eventPrint("You should start at page 1!");
      return 0;
    // pages can't be > 20
    } else if (pageNo > 20) {
      me->eventPrint("This book only holds 20 pages!");
      return 0;
    // don't allow the writing of blank pages
    } else if (entry3 == "") {
      me->eventPrint("It looks like you're trying to add a blank page.");
      return 0;
    // don't allow page 3 to be written if page 2 is blank, etc.
    } else if ( pageNo > sizeof(pages)+2) {
        me->eventPrint("But page " + (sizeof(pages)+1) +" isn't written yet!");
        return 0;
    // everything good, write a page
    } else {
      // previously written pages can be rewritten, but let the player know.
      if (pageNo < sizeof(pages)+1) {
        send_messages("erase",
          "$agent_name hurriedly $agent_verb a page in $target_name.",
          me, this_object(), environment(me));
      }
      pages["page "+pageNo] = entry3;
      CHAT_D->eventSendChannel("Book", "reports",
        capitalize(this_player()->GetKeyName()) +
        " wrote in a book: " + entry3);
    }
  // use syntax was totally unrecognized, give player syntax hint
  } else {
    me->eventPrint("You have to <use book to write on cover sometitle> "
      "or <use book to write on page 1 something>");
    return 0;
  }
  send_messages("scribble",
    "$agent_name $agent_verb something down on $target_name",
    me, this_object(), environment(me));
  SetupBook();
  return 1;
}

// Sets up the various properties of a book
void SetupBook() {
  // Book is untitled, it is a blank book, waiting to be written in.
  if (title == "") {
    SetLong("This untitled book is bound with stiff leather and cheap glue. "
+
      "You can <use book to write on cover> to write a title.");
    SetShort("a leather-bound book (untitled).");
  // Book has a title. It is bound to a player, and may be written in.
  } else {
    SetShort("a leather-bound book titled '" + title + "'");
    SetLong("This book is bound with stiff leather and cheap glue. " +
      "It is titled '" + title + "' by " + capitalize(authorFullName) + ". " +
      "It is 20 pages long, and contains "+ sizeof(pages) + " pages "
      "of writing. "
      "You could <use book to write on page " + (sizeof(pages)+1) +
      " something>. "
      "Or you could <read page 1 on book>."
    );
    // this is shown when player just types "read book"
    SetRead( "default", title + " by " + capitalize(authorFullName) +
      " is several pages long. Perhaps you should <read page 1 on book>?" );
    // this sets up "read page 1 on book" etc.
    foreach (string page in keys(pages)) {
      SetRead(page,pages[page]);
    }
  }
}

// debug function to show me pages
mapping GetPages() {
  return pages;
}

string GetAuthor() {
  return author;
}
