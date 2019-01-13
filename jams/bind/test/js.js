Module['glm'] = Module['glm'] || {};
Module['mud'] = Module['mud'] || {};
Module['mud']['gfx'] = Module['mud']['gfx'] || {};
Module['mud']['ui'] = Module['mud']['ui'] || {};
Module['toy'] = Module['toy'] || {};

(function() {
    function setupEnums() {
    }
    if (Module['calledRun']) setupEnums();
    else addOnPreMain(setupEnums);
})();
