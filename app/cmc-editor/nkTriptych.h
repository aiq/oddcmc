#ifndef NUKLEAR_NKTRIPTYCH_H
#define NUKLEAR_NKTRIPTYCH_H

#include "raylib-nuklear.h"

#include "stdio.h"

struct nkTriptych
{
   float minLeft;
   float minCenter;
   float minRight;
   float gap;
   float rows[5];
   int activeGap;
   struct nk_color passiveColor;
   struct nk_color activeColor;
};
typedef struct nkTriptych nkTriptych;

static void init_triptych_nk( nkTriptych tripty[static 1],
                              float minLeft,
                              float minCenter,
                              float minRight )
{
   tripty->minLeft = minLeft;
   tripty->minCenter = minCenter;
   tripty->minRight = minRight;
   tripty->gap = 3;
   tripty->rows[0] = minLeft;
   tripty->rows[1] = tripty->gap;
   tripty->rows[2] = minCenter;
   tripty->rows[3] = tripty->gap;
   tripty->rows[4] = minRight;
   tripty->activeGap = 0;
   tripty->passiveColor = nk_rgb( 0, 0, 0 );
   tripty->activeColor = nk_rgb( 255, 255, 255 );
}

static float triptych_min_width_nk( nkTriptych const tripty[static 1] )
{
   return tripty->minLeft + tripty->minCenter + tripty->minRight + tripty->gap*2;
}

static float triptych_width_nk( nkTriptych const tripty[static 1] )
{
   float res = 0.0f;
   for ( int i = 0; i < 5; ++i )
   {
      res += tripty->rows[i];
   }
   return res;
}

static void layout_triptych_nk( struct nk_context *ctx,
                                float width, float heigth,
                                nkTriptych tripty[static 1] )
{
   if ( width < triptych_min_width_nk( tripty ) )
   {
      tripty->rows[0] = tripty->minLeft;
      tripty->rows[2] = tripty->minCenter;
      tripty->rows[4] = tripty->minRight;
   }
   else
   {
      float const wings = tripty->rows[0] + tripty->rows[4] + tripty->gap*2;
      tripty->rows[2] = width - wings;
   }

   nk_layout_row( ctx, NK_STATIC, heigth, 5, tripty->rows );
}

static void left_center_gap_nk( struct nk_context *ctx,
                                nkTriptych tripty[static 1] )
{
   struct nk_input const* in = &ctx->input;
   struct nk_rect bounds = nk_widget_bounds(ctx);
   nk_spacing(ctx, 1);
   if ( !nk_input_is_mouse_down( in, NK_BUTTON_LEFT ) )
   {
      tripty->activeGap = 0;
   }
   {
      struct nk_command_buffer *canvas = nk_window_get_canvas(ctx);
      struct nk_color color = ( tripty->activeGap < 0 ) ? tripty->activeColor
                                                        : tripty->passiveColor;
      nk_fill_rect( canvas, bounds, 0, color );
   }
   if ( tripty->activeGap < 0 )
   {
      float l = tripty->rows[0] + in->mouse.delta.x;
      float c = tripty->rows[2] - in->mouse.delta.x;

      if ( l >= tripty->minLeft && c >= tripty->minCenter )
      {
         tripty->rows[0] = l;
         tripty->rows[2] = c;
      }
   }
   if ( tripty->activeGap == 0 &&
        nk_input_is_mouse_hovering_rect( in, bounds )  &&
        nk_input_is_mouse_down( in, NK_BUTTON_LEFT ) )
   {
      tripty->activeGap = -1;
   }
}

static void center_right_gap_nk( struct nk_context *ctx,
                                 nkTriptych tripty[static 1] )
{
   struct nk_input const* in = &ctx->input;
   struct nk_rect bounds = nk_widget_bounds(ctx);
   nk_spacing(ctx, 1);
   if ( !nk_input_is_mouse_down( in, NK_BUTTON_LEFT ) )
   {
      tripty->activeGap = 0;
   }
   {
      struct nk_command_buffer *canvas = nk_window_get_canvas(ctx);
      struct nk_color color = ( tripty->activeGap > 0 ) ? tripty->activeColor
                                                        : tripty->passiveColor;
      nk_fill_rect( canvas, bounds, 0, color );
   }
   if ( tripty->activeGap > 0 )
   {
      float c = tripty->rows[2] + in->mouse.delta.x;
      float r = tripty->rows[4] - in->mouse.delta.x;

      if ( r >= tripty->minRight && c >= tripty->minCenter )
      {
         tripty->rows[2] = c;
         tripty->rows[4] = r;
      }
   }
   if ( tripty->activeGap == 0 &&
        nk_input_is_mouse_hovering_rect( in, bounds )  &&
        nk_input_is_mouse_down( in, NK_BUTTON_LEFT ) )
   {
      tripty->activeGap = 1;
   }
}

#endif