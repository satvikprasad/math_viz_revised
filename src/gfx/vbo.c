#include "vbo.h"

struct VBO vbo_create(GLint type, b8 dynamic) {
    struct VBO self = {.type = type, .dynamic = dynamic};
    glGenBuffers(1, &self.handle);
    return self;
}

void vbo_destroy(struct VBO self) { glDeleteBuffers(1, &self.handle); }

void vbo_bind(struct VBO self) { glBindBuffer(self.type, self.handle); }

void vbo_buffer(struct VBO self, void *data, u64 offset, u64 count) {
    vbo_bind(self);
    glBufferData(self.type, count - offset, data,
                 self.dynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
}
