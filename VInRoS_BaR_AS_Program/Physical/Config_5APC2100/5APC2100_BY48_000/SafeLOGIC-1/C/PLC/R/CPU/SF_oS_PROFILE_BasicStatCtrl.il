. a s s e m b l y   e x t e r n   m s c o r l i b   { }  
 . a s s e m b l y   e x t e r n   _ _ F i e l d A t t r i b u t e   { }  
 . a s s e m b l y   e x t e r n   ' M a i n '   { }  
 . a s s e m b l y   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l '   { }  
 . m o d u l e   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' . d l l  
  
 . c l a s s   p u b l i c   a u t o   a n s i   b e f o r e f i e l d i n i t   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l '   e x t e n d s   [ m s c o r l i b ] S y s t e m . O b j e c t  
 {  
 . m e t h o d   p u b l i c   h i d e b y s i g   s p e c i a l n a m e   r t s p e c i a l n a m e  
         i n s t a n c e   v o i d     . c t o r ( )   c i l   m a n a g e d  
 {  
 . m a x s t a c k     8  
  
 l d c . i 4 . 0  
 s t s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ B O O L _ 0 '  
 l d c . i 4   0  
 s t s f l d   i n t 3 2   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ D I N T _ 0 '  
 l d c . i 4 . 0  
 s t s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 l d c . i 4   0  
 s t s f l d   u n s i g n e d   i n t 8   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B Y T E _ 0 '  
 l d c . i 4   - 1  
 s t s f l d   i n t 1 6   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E I N T _ - 1 '  
 l d c . i 4   0  
 s t s f l d   u n s i g n e d   i n t 1 6   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ W O R D _ 0 '  
 r e t  
 }  
  
  
 / /   l o c a l   v a r i a b l e s  
 . f i e l d   p u b l i c   b o o l   ' A c t i v a t e '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   u n s i g n e d   i n t 8   ' S _ P r o f i l e I D '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   i n t 1 6   ' S _ I n s t a n c e I D '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   u n s i g n e d   i n t 8   ' S _ C o n t r o l I D '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   u n s i g n e d   i n t 8   ' S _ S t a t u s I D '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ C o n t r o l _ B i t 0 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ C o n t r o l _ B i t 1 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ C o n t r o l _ B i t 2 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ C o n t r o l _ B i t 3 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ C o n t r o l _ B i t 4 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ C o n t r o l _ B i t 5 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ C o n t r o l _ B i t 6 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ C o n t r o l _ B i t 7 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 2   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' R e a d y '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ S t a t u s _ B i t 0 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ S t a t u s _ B i t 1 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ S t a t u s _ B i t 2 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ S t a t u s _ B i t 3 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ S t a t u s _ B i t 4 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ S t a t u s _ B i t 5 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ S t a t u s _ B i t 6 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' S _ S t a t u s _ B i t 7 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   b o o l   ' E r r o r '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   u n s i g n e d   i n t 1 6   ' D i a g C o d e '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   1 3   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   i n t 3 2   ' F i r s t C a l l '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   0 9   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
  
 / /   F B   i n s t a n c e s  
  
 . f i e l d   p u b l i c   s t a t i c   b o o l   ' _ _ C O N S T _ B O O L _ 0 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   0 A   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   s t a t i c   i n t 3 2   ' _ _ C O N S T _ D I N T _ 0 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   0 A   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   s t a t i c   b o o l   ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   0 A   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   s t a t i c   u n s i g n e d   i n t 8   ' _ _ C O N S T _ S A F E B Y T E _ 0 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   0 A   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   s t a t i c   i n t 1 6   ' _ _ C O N S T _ S A F E I N T _ - 1 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   0 A   0 0   0 0   0 0   F F   F F   F F   F F   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
 . f i e l d   p u b l i c   s t a t i c   u n s i g n e d   i n t 1 6   ' _ _ C O N S T _ W O R D _ 0 '  
 . c u s t o m   i n s t a n c e   v o i d   [ _ _ F i e l d A t t r i b u t e ] _ _ F i e l d A t t r i b u t e : : . c t o r ( v a l u e t y p e   [ _ _ F i e l d A t t r i b u t e ] F i e l d T y p e ,   i n t 3 2 ,   i n t 3 2 ,   i n t 3 2 ,   b o o l )   =   (   0 1   0 0   0 A   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   0 0   )  
  
 . m e t h o d   p u b l i c   h i d e b y s i g   i n s t a n c e   v o i d   _ _ c o l d s t a r t ( )   c i l   m a n a g e d  
 {  
 . m a x s t a c k     8  
  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' A c t i v a t e '  
 l d a r g . 0  
 l d s f l d   u n s i g n e d   i n t 1 6   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ W O R D _ 0 '  
 s t f l d   u n s i g n e d   i n t 1 6   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' D i a g C o d e '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' E r r o r '  
 l d a r g . 0  
 l d s f l d   i n t 3 2   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ D I N T _ 0 '  
 s t f l d   i n t 3 2   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' F i r s t C a l l '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' R e a d y '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l _ B i t 0 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l _ B i t 1 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l _ B i t 2 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l _ B i t 3 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l _ B i t 4 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l _ B i t 5 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l _ B i t 6 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l _ B i t 7 '  
 l d a r g . 0  
 l d s f l d   u n s i g n e d   i n t 8   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B Y T E _ 0 '  
 s t f l d   u n s i g n e d   i n t 8   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ C o n t r o l I D '  
 l d a r g . 0  
 l d s f l d   i n t 1 6   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E I N T _ - 1 '  
 s t f l d   i n t 1 6   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ I n s t a n c e I D '  
 l d a r g . 0  
 l d s f l d   u n s i g n e d   i n t 8   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B Y T E _ 0 '  
 s t f l d   u n s i g n e d   i n t 8   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ P r o f i l e I D '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s _ B i t 0 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s _ B i t 1 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s _ B i t 2 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s _ B i t 3 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s _ B i t 4 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s _ B i t 5 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s _ B i t 6 '  
 l d a r g . 0  
 l d s f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B O O L _ 0 '  
 s t f l d   b o o l   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s _ B i t 7 '  
 l d a r g . 0  
 l d s f l d   u n s i g n e d   i n t 8   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' _ _ C O N S T _ S A F E B Y T E _ 0 '  
 s t f l d   u n s i g n e d   i n t 8   ' S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' : : ' S _ S t a t u s I D '  
 r e t  
 }  
  
 . m e t h o d   p u b l i c   h i d e b y s i g   i n s t a n c e   v o i d   ' _ _ S F _ o S _ P R O F I L E _ B a s i c S t a t C t r l ' ( )   c i l   m a n a g e d  
 {  
     . m a x s t a c k   2 0  
  
     / /   N E T W O R K   0  
     I L _ 0 0 0 0 _ 0 0 0 0 :     r e t  
  
 }  
 }  
  
 