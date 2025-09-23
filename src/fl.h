#pragma once

typedef struct GlyphMetric
{
    float advance_x;
    float offset_x;
    float offset_y;
    float width;
    float height;

    float u0;
    float v0;
    float u1;
    float v1;

} GlyphMetric;

typedef struct FontAtlas
{
    void *pixels;
    int width;
    int height;
    float ascender;
    float dpi_scale;
    int channels;
    GlyphMetric *glyph_metrics;

} FontAtlas;

typedef struct GlyphQuad
{
    float screen_min_x;
    float screen_min_y;
    float screen_max_x;
    float screen_max_y;
    float tex_min_x;
    float tex_min_y;
    float tex_max_x;
    float tex_max_y;

} GlyphQuad;

FontAtlas font_loader_create_atlas(const char *path, int width, int height, float size, float dpi_scale, int channels);
GlyphQuad font_loader_get_glyph_quad(const FontAtlas *atlas, unsigned char ch, float x, float y);
float font_loader_get_advance_x(const FontAtlas *atlas, unsigned char ch);
float font_loader_get_ascender(const FontAtlas *atlas);
