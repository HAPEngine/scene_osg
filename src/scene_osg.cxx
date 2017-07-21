/** Modifies the linker so that it uses proper symbol names in MSVC. **/
#ifdef OS_Windows
#pragma comment(linker, "/EXPORT:create=create")
#pragma comment(linker, "/EXPORT:load=load")
#pragma comment(linker, "/EXPORT:update=update")
#pragma comment(linker, "/EXPORT:unload=unload")
#pragma comment(linker, "/EXPORT:destroy=destroy")
#endif


#include <hap.h>


class HapOpenSceneGraphModule {
  public:
	HapOpenSceneGraphModule(HAPEngine *engine) {
		(*this).engine = engine;
	}

	void onLoad(char *identifier) {
	}

	int onUpdate() {
	}

	void onUnload() {
	}

	~HapOpenSceneGraphModule() {
	}

  private:
	HAPEngine *engine;
};


/**
 * Wrap class in Hap-style module functions.
 */
extern "C"  {
	void* create(HAPEngine *engine) {
		return (void*) new HapOpenSceneGraphModule(engine);
	}

	void load(HAPEngine *engine, void *state, char *identifier) {
		HapOpenSceneGraphModule *m = (HapOpenSceneGraphModule*) state;

		if (m != NULL) (*m).onLoad(identifier);
	}

	HAPTime update(HAPEngine *engine, void *state) {
		HapOpenSceneGraphModule *m = (HapOpenSceneGraphModule*) state;

		if (m == NULL) return -1;

		return (*m).onUpdate();
	}

	void unload(HAPEngine *engine, void *state) {
		HapOpenSceneGraphModule *m = (HapOpenSceneGraphModule*) state;

		if (m != NULL) (*m).onUnload();
	}

	void destroy(HAPEngine *engine, void *state) {
		HapOpenSceneGraphModule *m = (HapOpenSceneGraphModule*) state;

		if (m != NULL) delete m;
	}
}
