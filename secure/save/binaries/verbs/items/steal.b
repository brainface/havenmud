MUDB	�I��L� secure/include/global.h secure/include/lib.h secure/include/dirs.h include/rounds.h include/position.h verbs/items/include/steal.h  verbs/items/steal.c  ��        X   t>@<>@�����    X  X  X                       [   *     -   , 	
, , , /y  .y  .� /y  .y
  .y 
 ../y  .y  .y  .y
  .y  ../y� cc?q6 cc y  y @@y� p   y�, ./?  y! .? 
? y� "c .y� cc?q6 c#c�$ qF c%c y  y @@y�� p   y��, ./? p� Sb?|* ? p ? .Cb?  y@�G  .y� cc?q6 c&c y  y @@y�� p   y��, ./�'�� �(
 �) /-   /st*       h�  5  ��     <�  �  8�   &   �   �   X�    }   �w   T  �%%���55$$  �� Ȣ�l�����>@�L l��� y H� �>@�q�{=@�q�@@�����$�>@H�8i�?"@T��>@�H X\�a p��,(��� � �,l\��<� h�t�drt�?@        lib/special/verb.c verbs/items/steal.c secure/include/global.h secure/include/lib.h secure/include/dirs.h include/rounds.h include/position.h verbs/items/include/steal.h steal OBJ from LIV WRD from LIV OBS from LIV Steal what from whom?� Syntax: <steal money from LIVING>
        <steal ITEM from LIVING>

Uses your stealing abilities to rob another of items or money.  Items are much harder to steal than money, and trying to steal multiple items in one shot is dangerous. GetSleeping" You cannot do that while sleeping! GetPosition  You should try that standing up! money stealing GetSkillLevel( You are not skillful enough at stealing. no steal GetProperty& Mystical forces prevent your thievery. GetStaminaPoints( You are too tired for such skullduggery. You eye  GetName  with thoughts on 	  pockets.
 eventPrint GetInCombat	 SetAttack But that isn't there!  does not have that.   GetShort .  possessions.
 eventSteal AddStaminaPoints eventMoralAct create
 eventSteal do_steal_obj_from_liv do_steal_obs_from_liv can_steal_wrd_from_liv do_steal_wrd_from_liv can_steal_obj_from_liv #global_init#--      
    x  �        
      d  �  �  
�  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  
�  �  �  �  �  	�  �  �  �  
�  �  
�  �  �  �  �  �  �  �  �  �  �  �  
�  �  �  
�  
�  �  �    