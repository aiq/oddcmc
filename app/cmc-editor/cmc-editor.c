#include "raylib.h"
#define RAYLIB_NUKLEAR_IMPLEMENTATION
#include "raylib-nuklear.h"

#include "tinyfiledialogs.h"
#include "tinyfiledialogs.c"
#include "nkStringBuffer.h"
#include "nkTriptych.h"

#include "clingo/string/CString.h"
#include "oddcmc/OCmc.h"

struct appModel
{
   CString* path;
   OCmc* cmc;
};
typedef struct appModel appModel;

int main(void)
{
   // ----------------------------------------------------------- Initialization
   SetConfigFlags( FLAG_WINDOW_RESIZABLE );
   InitWindow( 1280, 720, "cmc-editor" );

   nkTriptych tripty;
   init_triptych_nk( &tripty, 200, 200, 200 );

   SetTargetFPS( 60 ); // Set our game to run at 60 frames-per-second

   // ---------------------------------------------------------------------- GUI
   struct nk_colorf bg = ColorToNuklearF( SKYBLUE );
   struct nk_context *ctx = InitNuklear( 10 );
   struct nk_color col = nk_rgb( 100, 100, 100 );

   // Main game loop
   while ( !WindowShouldClose() ) // Detect window close button or ESC key
   {
      UpdateNuklear( ctx );

      int h = GetScreenHeight();
      int w = GetScreenWidth();

      if ( nk_begin( ctx, "mainscreen", nk_rect( 0, 0, w, h ),
                     NK_WINDOW_SCROLL_AUTO_HIDE|NK_WINDOW_BACKGROUND) )
      {
         // ------------------------------------------------------------ menubar
         {
            nk_menubar_begin( ctx );

            nk_layout_row_begin( ctx, NK_STATIC, 25, 1 );
            nk_layout_row_push( ctx, 45 );
            if ( nk_menu_begin_label( ctx, "menu", NK_TEXT_LEFT,
                 nk_vec2( 120, 200 ) ) )
            {
               nk_layout_row_dynamic( ctx, 25, 1 );
               if ( nk_menu_item_label( ctx, "open", NK_TEXT_LEFT ) )
               {
                  char* filename = tinyfd_openFileDialog(
		             "let us read the password back",
		             "",
		             0,
		             NULL,
		             NULL,
		             0 );
                  if ( filename != NULL )
                  {
                     printf( "filename: %s", filename );
                  }
                  else
                  {
                     printf( "no file selected" );
                  }
               }
               nk_menu_end(ctx);
            }
            nk_menubar_end(ctx);
         }

         const struct nk_input *in = &ctx->input;
         struct nk_vec2 size = nk_window_get_size ( ctx );
         layout_triptych_nk( ctx, size.x-40, size.y-50, &tripty );
         {
           // ------------------------------------------------------- left space
           if ( nk_group_begin( ctx, "left", NK_WINDOW_SCROLL_AUTO_HIDE ) )
           {
              nk_layout_row_dynamic( ctx, 25, 1 );
              nk_labelf( ctx, NK_TEXT_LEFT, "lMin: %f", tripty.minLeft );
              nk_labelf( ctx, NK_TEXT_LEFT, "l: %f", tripty.rows[0] );



              if ( nk_tree_push( ctx, NK_TREE_NODE, "Input", NK_MINIMIZED ) )
              {
                 static const float ratio[] = { 60, 150 };
                 nk_layout_row( ctx, NK_STATIC, 25, 2, ratio );

                 static_string_buffer_c_( defaultBuf, 64 );
                 nk_label( ctx, "Default:", NK_TEXT_LEFT );
                 edit_string_nk( ctx, NK_EDIT_FIELD, &defaultBuf, nk_filter_default );

                 static_string_buffer_c_( fieldBuf, 64 );
                 nk_label( ctx, "Field:", NK_TEXT_LEFT );
                 edit_string_nk( ctx, NK_EDIT_FIELD, &fieldBuf, nk_filter_default );

                 static_string_buffer_c_( bufferBuf, 64 );
                 nk_label( ctx, "Buffer:", NK_TEXT_LEFT );
                 edit_string_nk( ctx, NK_EDIT_FIELD, &bufferBuf, nk_filter_default );

                 nk_tree_pop( ctx );
              }

              nk_group_end(ctx);
           }

           left_center_gap_nk( ctx, &tripty );

           // ----------------------------------------------------- middle space
           if ( nk_group_begin( ctx, "center", NK_WINDOW_SCROLL_AUTO_HIDE ) )
           {
              nk_layout_row_dynamic( ctx, 25, 1 );
              nk_labelf( ctx, NK_TEXT_CENTERED, "cMin: %f", tripty.minCenter );
              nk_labelf( ctx, NK_TEXT_CENTERED, "c: %f", tripty.rows[2] );
              nk_labelf( ctx, NK_TEXT_CENTERED, "tripty min width: %f",
                         triptych_min_width_nk( &tripty ) );
              nk_labelf( ctx, NK_TEXT_CENTERED, "tripty width: %f",
                         triptych_width_nk( &tripty ) );
              nk_labelf( ctx, NK_TEXT_CENTERED, "width: %d", w );
              nk_labelf( ctx, NK_TEXT_CENTERED, "height: %d", h );
              nk_group_end( ctx );
           }

           center_right_gap_nk( ctx, &tripty );

           // ------------------------------------------------------ right space
           if ( nk_group_begin( ctx, "right", NK_WINDOW_SCROLL_AUTO_HIDE ) )
           {
              nk_layout_row_dynamic(ctx, 25, 1);
              nk_labelf(ctx, NK_TEXT_LEFT, "rMin: %f", tripty.minRight);
              nk_labelf(ctx, NK_TEXT_LEFT, "r: %f", tripty.rows[4]);
              nk_group_end(ctx);
           }
        }

        }
        nk_end( ctx );

        // ---------------------------------------------------------------- Draw
        BeginDrawing();
           ClearBackground(ColorFromNuklearF(bg));
           DrawNuklear(ctx);
        EndDrawing();
    }

    // ------------------------------------------------------- De-Initialization
    UnloadNuklear(ctx);     // Unload the Nuklear GUI
    CloseWindow();

    return 0;
}
