MUDB	�I��J� secure/include/global.h secure/include/lib.h secure/include/dirs.h secure/include/rooms.h secure/include/dirs.h secure/include/objects.h secure/include/dirs.h secure/include/daemons.h secure/include/dirs.h  realms/zaxan/workroom.c�	  �3)  �     X   tC@$C@�����  |           �	  �	  �	  �	          � 1   X 2   - a  2, ,� ,= 	,w   ,7 
p� ,, D.aD/aD0a D1a/- �    y 2   !!""##$$%%/y� &'@y/.?  /? q� m% ? qd % � 0 .C/# &q� (c? &)�* c+c/C.7 � C1 &,�. &-�&)�* c+c/./?  /? q� m% ? qd % � 0 .C0 @.@y? qt /./&/@y.,�   .D0a01 2@yqt &34,3 ./,�   .D0a01 2@yqt &5,3 ./yqd  /C0 @6�qr  y dhyqt .//,�   .D.aD/a01 2@yqt &7,= ./,�   .C.m& C/m .D.aD/a8,= 01 2@yqt &9@y./?  &:@y.? �b ,�   .? �@_ &�q� ;cy.�� &<@y.�� &�q� =cy.?  D1`#>@y?qt ./?  &?@y.? �b ,�   .�� &<@y.�� &�q� @cy.?  D1V&A? q� cBcy./C/m& C.m &Cy C/ &Dy
 &Ey.,�   .01 2@yqt &FyD.aD/aG,= ./? � H.?  I. J? �
~c.K./&Ly&M@�Gq� cNc@�G,� cyb # &O��Gq� cNc��G,� cy# ��|' ./,�   .? @_ &P? cBcy.?Q 9 ?R?Q  ? &Sy TUy?qt .1 ?RV ? &Sy TUy?qt ../yq  &Wy/.- �  /U4��   �  �� �  ��  X  ��   3  �(   �  t*       Ѐ ~  $�  %  @�  �   P@   R   `�   j  �!     ��"     ��(   �   ��+   �  83   �  H:   �  Te>  �  �/?  .  �w   *  ��c�����%���ŀ%%%c�%h�c�q�%u�v�w�y�{�%%%%%%%%%%%%%%%%%%ƀ%%%%%$  �3)Ȣ�l��3@x2@�i��B@��B@����>@p�Xf2L~\�8�83$���+,��!�������X}<�,�T��`��(H:�����/?Ѐ��T#9��;@�7*X\��1@��5@<OQ@�A@ (4@�=<�@�1@h�@�?G@<�M@Ё)@tg0@(�B@�mk@$N*$D�O=@Hn9@�:@�q*$o9�5*Ĉ�X*�M@̖*@d�>@ b@L�B@,+ �LM@�*� �c�<FD.�	@P�9@�W� b@@-2@�c>�,�����p*Eȑ@@        lib/rooms/room.c realms/zaxan/workroom.c secure/include/global.h secure/include/lib.h secure/include/dirs.h secure/include/rooms.h secure/include/objects.h secure/include/daemons.h indoorsw The Home of %^WHITE%^BOLD%^Zaxan%^RESET%^ %^WHITE%^BOLD%^Zimtafarous%^RESET%^ [%^GREEN%^BOLD%^access required%^RESET%^]? This is where the mighty Zaxan does his idling...I mean...work. north /domains/staff/staffroom zaxan milquitoast amelia laoise zzaxan lockstat list commands command	 cmd_check quit goto ed rm update dest duc
 GetKeyName lockup unlock rmexits addexits lockout invite uninvite eject system	 Piss off.!  has locked the room for privacy. %^BLUE%^BOLD%^ GetName+  just tried to penetrate the seal!%^RESET%^$ You have entered with an invitation.: The room is locked. Only those that are invited may enter.m A large wall of %^GREEN%^green vines%^RESET%^ envelop $target_name to prevent $target_objective from leaving!�command(s) : This info.
lockstat   : Status check of room's locks.
list       : List of owner and guests.
----------------------------------------------------------------
lockup     : Locks room, only invited people may enter.
lockout    : Only owner and admins may enter.
rmexits    : Removes all exits from the room.
addexits   : Re-adds all exits to theroom.
unlock     : Unlocks room. Anyone may enter.
invite     : Invites a specific person to enter the locked room.
uninvite   : Removes a person from the invite list.
eject      : Ejects a target to its last known environment.
---------------------------------------------------------------- mumble wink: $agent_name $agent_verb an ancient phrase and $agent_verb.< Many %^GREEN%^green vines%^RESET%^ suddenly cover the walls.$ %^GREEN%^covered with vines%^RESET%^9 The %^GREEN%^green vines%^RESET%^ retreat into the walls.� A large wall of %^GREEN%^green vines%^RESET%^ envelops $target_name to prevent $target_objective from performing a forbidden action!4 Shield Set: %^GREEN%^BOLD%^access required%^RESET%^!M The Home of %^WHITE%^BOLD%^Zaxan%^RESET%^ %^WHITE%^BOLD%^Zimtafarous%^RESET%^  The room's seal has been broken. Invite whom?  is not logged on., You can't invite yourself. You're the owner!  is already invited.E $agent_name $agent_verb $target_name into $agent_possessive workroom. Uninvite whom?  is already uninvited. You uninvite  . Shields down.' %^RED%^BOLD%^Maximum security!%^RESET%^6 %^GREEN%^BOLD%^Access by invitation required.%^RESET%^* Shield Set: %^RED%^BOLD%^maximum%^RESET%^!l The Home of %^WHITE%^BOLD%^Zaxan%^RESET%^ %^WHITE%^BOLD%^Zimtafarous%^RESET%^ [%^RED%^BOLD%^secure%^RESET%^] not in the game right now
 right here at  somewhere...not really sure... Permanent list: Host      is  Guest    Failed to locate:  GetLastEnvironment	 eventMove' %^BOLD%^%^RED%^EJECT FAILED!!!%^RESET%^ removeE $agent_name $agent_verb $target_name from $agent_possessive workroom! /domains/staff/room/start Uh...no!	 is_locked lockout noexits allowed_pers lockout invite
 CanRelease lockup rmexits create eject list
 CanReceive init unlock	 cmd_check PreExit
 CheckOwner commands lockstat addexits	 more_list uninvite #global_init#>>(      
    x  �      x  
      x        x  Q  � c  d  e  f  h  i  j  k  l  m  n  s  u  v  
w  y  {  }  ~    �  �  �  �  �  �  �  �  "�  �  �  	�  �  �  �  �  �  �  �  �  �  �  �  �  "�  �  �  
�  	�  �  	�  �  �  
�  	�  �  	�  �  �  	�  
�  �        	      	      
  	   !  #  $  %  	&  (  )  2  
4  7  	9  	;  >  	=  >  A  
D  G  J  	I  J  M  O  V  
X  [  	]  _  
b  e  h  	g  h  	k  m  l  m  t  u  v  w  
z  	�  	�  �  �  �  �  
�  	�  �  �  �  �  �  �  �  �  �  �  �  �  	�  �  �  
�  �  	�  �  �  
�  	�  �  �  	�  �  U    