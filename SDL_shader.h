#pragma once

#include "SDL.h"
#ifdef SDL_SHADER_GL_STANDALONE
#include "SDL_opengl.h"
#include "SDL_opengl_glext.h"
#endif

#include <fstream>
#include <string>
#include <vector>

bool _SDL_LoadedShaderFunctions = false;

#ifdef SDL_SHADER_GL_STANDALONE
PFNGLCREATESHADERPROC            glCreateShader;
PFNGLSHADERSOURCEPROC            glShaderSource;
PFNGLCOMPILESHADERPROC           glCompileShader;
PFNGLGETSHADERIVPROC             glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC        glGetShaderInfoLog;
PFNGLDELETESHADERPROC            glDeleteShader;
PFNGLATTACHSHADERPROC            glAttachShader;
PFNGLCREATEPROGRAMPROC           glCreateProgram;
PFNGLLINKPROGRAMPROC             glLinkProgram;
PFNGLVALIDATEPROGRAMPROC         glValidateProgram;
PFNGLGETPROGRAMIVPROC            glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC       glGetProgramInfoLog;
PFNGLUSEPROGRAMPROC              glUseProgram;
PFNGLBINDFRAGDATALOCATIONPROC    glBindFragDataLocation;
PFNGLGETUNIFORMLOCATIONPROC      glGetUniformLocation;
PFNGLUNIFORM1FPROC               glUniform1f;
PFNGLUNIFORM3FPROC               glUniform3f;
PFNGLUNIFORM4FPROC               glUniform4f;
PFNGLUNIFORM1IPROC               glUniform1i;
PFNGLGENVERTEXARRAYSPROC         glGenVertexArrays;
PFNGLBINDVERTEXARRAYPROC         glBindVertexArray;
PFNGLGENBUFFERSPROC              glGenBuffers;
PFNGLBINDBUFFERPROC              glBindBuffer;
PFNGLBUFFERDATAPROC              glBufferData;
PFNGLVERTEXATTRIBPOINTERPROC     glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLACTIVETEXTUREPROC           glActiveTexture1;
PFNGLGENFRAMEBUFFERSPROC         glGenFramebuffers;
PFNGLBINDFRAMEBUFFERPROC         glBindFramebuffer;
PFNGLFRAMEBUFFERTEXTUREPROC      glFramebufferTexture;
PFNGLFRAMEBUFFERTEXTURE2DPROC    glFramebufferTexture2D;
PFNGLDRAWBUFFERSPROC             glDrawBuffers;
PFNGLCHECKFRAMEBUFFERSTATUSPROC  glCheckFramebufferStatus;
PFNGLGETTEXTUREIMAGEEXTPROC      glGetTextureImage;
#endif

void SDL_GL_LoadShaderFunctions() {
#ifdef SDL_SHADER_GL_STANDALONE
    glCreateShader            = (PFNGLCREATESHADERPROC)SDL_GL_GetProcAddress("glCreateShader");
	glShaderSource            = (PFNGLSHADERSOURCEPROC)SDL_GL_GetProcAddress("glShaderSource");
	glCompileShader           = (PFNGLCOMPILESHADERPROC)SDL_GL_GetProcAddress("glCompileShader");
	glGetShaderiv             = (PFNGLGETSHADERIVPROC)SDL_GL_GetProcAddress("glGetShaderiv");
	glGetShaderInfoLog        = (PFNGLGETSHADERINFOLOGPROC)SDL_GL_GetProcAddress("glGetShaderInfoLog");
	glDeleteShader            = (PFNGLDELETESHADERPROC)SDL_GL_GetProcAddress("glDeleteShader");
	glAttachShader            = (PFNGLATTACHSHADERPROC)SDL_GL_GetProcAddress("glAttachShader");
	glCreateProgram           = (PFNGLCREATEPROGRAMPROC)SDL_GL_GetProcAddress("glCreateProgram");
	glLinkProgram             = (PFNGLLINKPROGRAMPROC)SDL_GL_GetProcAddress("glLinkProgram");
	glValidateProgram         = (PFNGLVALIDATEPROGRAMPROC)SDL_GL_GetProcAddress("glValidateProgram");
	glGetProgramiv            = (PFNGLGETPROGRAMIVPROC)SDL_GL_GetProcAddress("glGetProgramiv");
	glGetProgramInfoLog       = (PFNGLGETPROGRAMINFOLOGPROC)SDL_GL_GetProcAddress("glGetProgramInfoLog");
	glUseProgram              = (PFNGLUSEPROGRAMPROC)SDL_GL_GetProcAddress("glUseProgram");
    glBindFragDataLocation    = (PFNGLBINDFRAGDATALOCATIONPROC)SDL_GL_GetProcAddress("glBindFragDataLocation");
    glGetUniformLocation      = (PFNGLGETUNIFORMLOCATIONPROC)SDL_GL_GetProcAddress("glGetUniformLocation");
    glUniform1f               = (PFNGLUNIFORM1FPROC)SDL_GL_GetProcAddress("glUniform1f");
    glUniform3f               = (PFNGLUNIFORM3FPROC)SDL_GL_GetProcAddress("glUniform3f");
    glUniform4f               = (PFNGLUNIFORM4FPROC)SDL_GL_GetProcAddress("glUniform4f");
    glUniform1i               = (PFNGLUNIFORM1IPROC)SDL_GL_GetProcAddress("glUniform1i");
    glGenVertexArrays         = (PFNGLGENVERTEXARRAYSPROC)SDL_GL_GetProcAddress("glGenVertexArrays");
    glBindVertexArray         = (PFNGLBINDVERTEXARRAYPROC)SDL_GL_GetProcAddress("glBindVertexArray");
    glGenBuffers              = (PFNGLGENBUFFERSPROC)SDL_GL_GetProcAddress("glGenBuffers");
    glBindBuffer              = (PFNGLBINDBUFFERPROC)SDL_GL_GetProcAddress("glBindBuffer");
    glBufferData              = (PFNGLBUFFERDATAPROC)SDL_GL_GetProcAddress("glBufferData");
    glVertexAttribPointer     = (PFNGLVERTEXATTRIBPOINTERPROC)SDL_GL_GetProcAddress("glVertexAttribPointer");
    glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)SDL_GL_GetProcAddress("glEnableVertexAttribArray");
    glActiveTexture1          = (PFNGLACTIVETEXTUREPROC)SDL_GL_GetProcAddress("glActiveTexture");
    glGenFramebuffers         = (PFNGLGENFRAMEBUFFERSPROC)SDL_GL_GetProcAddress("glGenFramebuffers");
    glBindFramebuffer         = (PFNGLBINDFRAMEBUFFERPROC)SDL_GL_GetProcAddress("glBindFramebuffer");
    glFramebufferTexture      = (PFNGLFRAMEBUFFERTEXTUREPROC)SDL_GL_GetProcAddress("glFramebufferTexture");
    glFramebufferTexture2D    = (PFNGLFRAMEBUFFERTEXTURE2DPROC)SDL_GL_GetProcAddress("glFramebufferTexture2D");
    glDrawBuffers             = (PFNGLDRAWBUFFERSPROC)SDL_GL_GetProcAddress("glDrawBuffers");
    glCheckFramebufferStatus  = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)SDL_GL_GetProcAddress("glCheckFramebufferStatus");
#endif
    _SDL_LoadedShaderFunctions = true;
}

static const std::string _SDL_FragmentShaderHeader =
R"(
    #version 440
    in vec2 fragCoord;
    varying out vec4 fragColor;
    uniform int iFrame;
    uniform float iTime;
    uniform vec3 iResolution;
    uniform vec4 iMouse;
    uniform sampler2D iChannel0;
)";

static const std::string _SDL_VertexShaderHeader =
R"(
    #version 120
    uniform vec3 iResolution;
    varying out vec2 fragCoord;
)";

/**
 *  \brief A structure representing a single vertex and fragment shader pair
 */
class SDL_Shader {
public:
    SDL_Window* window;

    std::string vert_src, frag_src;

    // Uniforms
    GLint utime,
          uresolution,
          umouse,
          uchannel0;

    GLuint program;
    
    // Texture input
    GLuint texture;
    uint32_t* buf;
    int width, height;

    // Framebuffer
    GLuint framebuffer, framebuffer_texture;
    uint32_t* framebuffer_buf;

    bool va_created = false;
};

bool SDL_CompileShader(GLuint shader, const char* source, GLint* log_size = nullptr) {
    GLint result;

    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

    if (log_size)
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, log_size);

    return result != 0;
}

SDL_Shader* SDL_CreateShader(SDL_Window* window, const char* vertex_shader_path, const char* fragment_shader_path, bool append_headers = true) {
    if (!_SDL_LoadedShaderFunctions) SDL_GL_LoadShaderFunctions();

    std::ifstream vertex_shader(vertex_shader_path),
                  fragment_shader(fragment_shader_path);

    if (!(vertex_shader.is_open() && vertex_shader.good())) {
        SDL_SetError("Couldn't open vertex shader file \"%s\"", vertex_shader_path);

        return nullptr;
    }

    if (!(fragment_shader.is_open() && fragment_shader.good())) {
        SDL_SetError("Couldn't open fragment shader file \"%s\"", fragment_shader_path);

        return nullptr;
    }

    GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER),
           frag_shader = glCreateShader(GL_FRAGMENT_SHADER);

    SDL_Shader* shader = new SDL_Shader();

    shader->window = window;

    std::getline(std::ifstream(vertex_shader_path), shader->vert_src, '\0');
    std::getline(std::ifstream(fragment_shader_path), shader->frag_src, '\0');

    if (append_headers) {
        shader->frag_src = _SDL_FragmentShaderHeader + shader->frag_src;
        shader->vert_src = _SDL_VertexShaderHeader + shader->vert_src;
    }

    const char* vert_src_ptr = shader->vert_src.c_str();
    const char* frag_src_ptr = shader->frag_src.c_str();

    GLint log_size = 0;

    if (!SDL_CompileShader(vert_shader, vert_src_ptr, &log_size)) {
        SDL_SetError("Vertex shader compilation failed");

        delete shader;
        return nullptr;
    }

    if (!SDL_CompileShader(frag_shader, frag_src_ptr, &log_size)) {
        std::vector <char> log;

        log.resize(log_size);

        glGetShaderInfoLog(frag_shader, log_size, &log_size, log.data());

        SDL_SetError("%s", log.data());

        delete shader;
        return nullptr;
    }

    shader->program = glCreateProgram();
    glAttachShader(shader->program, vert_shader);
    glAttachShader(shader->program, frag_shader);
    glLinkProgram(shader->program);

    shader->utime = glGetUniformLocation(shader->program, "iTime");
    shader->uresolution = glGetUniformLocation(shader->program, "iResolution");
    shader->umouse = glGetUniformLocation(shader->program, "iMouse");
    shader->uchannel0 = glGetUniformLocation(shader->program, "iChannel0");

    GLint result;

    glValidateProgram(shader->program);
    glGetProgramiv(shader->program, GL_LINK_STATUS, &result);
    glGetProgramiv(shader->program, GL_INFO_LOG_LENGTH, &log_size);

    if (!result) {
        SDL_SetError("Shader link failed");

        delete shader;
        return nullptr;
    }
    
    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);

    return shader;
}

void SDL_ShaderSetUniform1I(SDL_Shader* shader, std::string name, int i) {
    GLuint uniform = glGetUniformLocation(shader->program, name.c_str());

    glUniform1i(uniform, i);
}

void SDL_ShaderSetUniform1F(SDL_Shader* shader, std::string name, float f) {
    GLuint uniform = glGetUniformLocation(shader->program, name.c_str());

    glUniform1f(uniform, f);
}

void SDL_ShaderBindRawTexture(SDL_Shader* shader, uint32_t* data, int width, int height) {
    if (!shader->va_created) {
        GLuint vao, vbo;

        // Generate and bind VAO
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // Generate VBO
        glGenBuffers(1, &vbo);

        static GLfloat const quad[12] = {
            -1.f, -1.f, 0.f,
            -1.f, +1.f, 0.f,
            +1.f, -1.f, 0.f,
            +1.f, +1.f, 0.f,
        };

        // Bind VBO
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glEnableVertexAttribArray(0);

        glGenTextures(1, &shader->texture);
        glBindTexture(GL_TEXTURE_2D, shader->texture);
        // set the texture wrapping/filtering options (on the currently bound texture object)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        shader->va_created = true;
    }

    shader->width = width;
    shader->height = height;
    shader->buf = data;
}

bool SDL_CreateShaderFramebuffer(SDL_Shader* shader) {
    glGenFramebuffers(1, &shader->framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, shader->framebuffer);

    glGenTextures(1, &shader->framebuffer_texture);
    glBindTexture(GL_TEXTURE_2D, shader->framebuffer_texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Give an empty image to OpenGL ( the last "0" )
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, shader->width, shader->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);

    glBindTexture(GL_TEXTURE_2D, 0);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, shader->framebuffer_texture, 0);

    // Set the list of draw buffers.
    GLenum draw_buffers[1] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(1, draw_buffers);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        SDL_SetError("Shader framebuffer creation failed, status=%u", glCheckFramebufferStatus(GL_FRAMEBUFFER));

        return false;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return true;
}

void SDL_UseShader(SDL_Shader* shader) {
    //glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, shader->texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, shader->width, shader->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, shader->buf);

    glUseProgram(shader->program);
    glUniform3f(shader->uresolution, (double)shader->width, (double)shader->height, 0.0f);
    SDL_ShaderSetUniform1I(shader, "DECODER_FIR_SIZE", 3);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    //glRect(-1, -1, 1, 1);
}

void SDL_UseShaderWithFramebuffer(SDL_Shader* shader, uint32_t* buf) {
    glBindFramebuffer(GL_FRAMEBUFFER, shader->framebuffer);

    SDL_UseShader(shader);

    glReadPixels(0, 0, shader->width, shader->height, GL_RGBA, GL_UNSIGNED_BYTE, buf);

    //std::cout << std::hex << buf[0] << std::endl;

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// struct SDL_MultipassShader {
//     std::vector <SDL_Shader*> passes;
//     std::vector <std::vector <uint32_t>> buffers;

//     int width, height;
// };

// SDL_MultipassShader SDL_CreateMultipassShader(int pass_count) {
//     passes.resize(pass_count);

// }

// void SDL_ShaderAddPass(SDL_Shader* pass) {

// }

// void SDL_RenderViewToBuffer(uint32_t* tex, uint32_t* buf) {
//     glBindFramebuffer(GL_FRAMEBUFFER, 0);

//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, shader->texture);
//     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, shader->width, shader->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex);
// }

// struct SDL_MultipassShader {
//     SDL_Shader** passes = nullptr;
//     size_t* order = nullptr;

//     int index = 0, size = 0;
// };

// SDL_MultipassShader* SDL_CreateMultipassShader(int passes, bool custom_order) {
//     SDL_MultipassShader* mp = new SDL_MultipassShader;

//     mp->size = passes;
//     mp->passes = new SDL_Shader*[passes];

//     if (custom_order) {
//         mp->order = new int[passes];
//     }
// }

