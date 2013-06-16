
#include <stdio.h>
#include <stdlib.h>
#include <bakge/Bakge.h>

int ThreadFunc(void* Data)
{
    bakge::Window* Win;

    Win = (bakge::Window*)Data;
    /* While window is open, print dots from this thread */
    while(Win->IsOpen()) {
        bakge::Delay(100000);
        printf(".");
        fflush(0);
    }
    printf("\n");

    return 0;
}


int main(int argc, char* argv[])
{
    printf("Initializing Bakge\n");
    bakge::Init(argc, argv);

    bakge::Window* Win;
    bakge::Thread* Thr;

    Win = bakge::Window::Create(600, 400);
    Thr = bakge::Thread::Create(ThreadFunc, (void*)Win);

    bakge::Event Ev;

    glClearColor(1, 0, 0, 1);
    glViewport(0, 0, 600, 400);

    while(1) {
        while(Win->PollEvent(&Ev) == BGE_SUCCESS) {
            if(Ev.Type == -1)
                Win->Close();
        }

        /* Don't draw if the window has closed */
        if(Win->IsOpen() == false)
            break;

        Win->Bind();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Win->SwapBuffers();
        Win->Unbind();
    }

    if(Win != NULL)
        delete Win;

    if(Thr != NULL)
        delete Thr;

    printf("Deinitializing Bakge\n");
    bakge::Deinit();

    return 0;
}
