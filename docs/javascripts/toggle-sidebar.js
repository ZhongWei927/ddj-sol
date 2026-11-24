(function() {
    const CONFIG = {
        navigationDefault: true,
        tocDefault: true,
        toggleButton: "all", // "none" | "navigation" | "toc" | "all"
        enableKeyboardShortcuts: true,
        buttonIcon: "&#9776;", // Replace with your icon/SVG markup if desired
        tooltips: {
            both: "Toggle navigation and TOC",
            nav: "Toggle navigation",
            toc: "Toggle TOC"
        }
    };

    const customDynamicStyle = document.createElement("style");
    customDynamicStyle.id = "zensical-toggle-sidebar-dynamic-style";
    // We must put it outside of the head and body, since they are replaced by instant navigation
    document.documentElement.appendChild(customDynamicStyle);

    const buttonStyle = document.createElement("style");
    buttonStyle.id = "zensical-toggle-sidebar-button-style";
    buttonStyle.textContent = `
        .mkdocs-toggle-sidebar-button {
            display: inline-flex;
            align-items: center;
            justify-content: center;
            flex: 0 0 auto;
            min-width: 2rem;
            height: 2rem;
            padding: 0 0.5rem;
            margin-right: 0.5rem;
            // border: 1px solid currentColor;
            border-radius: 0.25rem;
            background: transparent;
            color: inherit;
            font-size: 1rem;
            line-height: 1;
            white-space: nowrap;
            cursor: pointer;
            user-select: none;
            opacity: 0.85;
            transition: opacity 0.15s ease, background-color 0.15s ease;
        }

        .mkdocs-toggle-sidebar-button:hover {
            opacity: 1;
            background-color: rgba(127, 127, 127, 0.14);
        }

        .mkdocs-toggle-sidebar-button:focus-visible {
            outline: 2px solid currentColor;
            outline-offset: 2px;
        }
    `;
    document.documentElement.appendChild(buttonStyle);

    const TOGGLE_BUTTON_REFERENCE_ELEMENT_NOT_FOUND_WARNING =
        "[mkdocs-toggle-sidebar-plugin] Reference element for inserting 'toggle_button' not found. This version of the plugin may not be compatible with this version of the theme. Try updating both to the latest version. If that fails, you can open an GitHub issue.";

    const loadBool = (name, default_value) => {
        const value = localStorage.getItem(`TOGGLE_SIDEBAR_${name}`);
        if (value == null) {
            return default_value;
        } else {
            return value == "1";
        }
    };

    const loadNavigationState = () => loadBool("NAVIGATION", CONFIG.navigationDefault);
    const loadTocState = () => loadBool("TOC", CONFIG.tocDefault);

    const saveBool = (name, value) => {
        localStorage.setItem(`TOGGLE_SIDEBAR_${name}`, value ? "1" : "0");
    };

    const toggleVisibility = (toggleNavigation, toggleTOC) => {
        let newNavigation = loadNavigationState();
        let newTOC = loadTocState();

        if (toggleNavigation) {
            newNavigation = !newNavigation;
            saveBool("NAVIGATION", newNavigation);
        }
        if (toggleTOC) {
            newTOC = !newTOC;
            saveBool("TOC", newTOC);
        }

        _setVisibility(newNavigation, newTOC);
    };

    const _setVisibility = (newNavigation, newTOC) => {
        console.debug(`Setting new visibility: navigation=${newNavigation}, TOC=${newTOC}`);
        customDynamicStyle.innerHTML = setCombinedVisibility(newNavigation, newTOC);
    };

    const shouldKeyEventBeIgnored = (event) => {
        if (event.defaultPrevented) {
            return true;
        }
        if (event.target instanceof Element) {
            if (event.target.matches("input, textarea, select") || event.target.isContentEditable) {
                return true;
            }
        }
        return false;
    };

    let keyboardHandlerRegistered = false;
    const registerNativeHtmlKeyboardEventHandler = () => {
        if (keyboardHandlerRegistered) return;
        keyboardHandlerRegistered = true;

        document.addEventListener("keydown", (event => {
            if (shouldKeyEventBeIgnored(event)) {
                // do nothing
            } else {
                if (coreEventListenerLogic(event.key)) {
                    event.preventDefault();
                    event.stopPropagation();
                }
            }
        }));
    };

    // START OF INCLUDE
    const setCombinedVisibility = (showNavigation, showTOC) => {
        const cssRules = [];

        if (!showNavigation) {
            cssRules.push(`
                [data-zensical-nav],
                .zensical-sidebar--primary,
                .md-sidebar--primary {
                    display: none !important;
                }
            `);
        }

        if (!showTOC) {
            cssRules.push(`
                [data-zensical-toc],
                .zensical-sidebar--secondary,
                .md-sidebar--secondary {
                    display: none !important;
                }
            `);
        }

        if (!showNavigation || !showTOC) {
            cssRules.push(`
                [data-zensical-main],
                .zensical-content,
                .md-content {
                    max-width: 100% !important;
                }
            `);
        }

        return cssRules.join("\n");
    };

    const unwrapStaleLogoGroup = () => {
        document.querySelectorAll("body > header > nav .zensical-logo-toggle-group").forEach((group) => {
            const parent = group.parentNode;
            if (!parent) return;
            while (group.firstChild) {
                parent.insertBefore(group.firstChild, group);
            }
            group.remove();
        });
    };

const findLogoAnchor = () => {
        return (
            document.querySelector("body > header > nav a.md-logo") ||
            document.querySelector("body > header > nav .md-logo")
        );
    };

    const addToggleButton = (toggleNavigation, toggleTOC) => {
        unwrapStaleLogoGroup();

        const logoAnchor = findLogoAnchor();
        if (!logoAnchor || !logoAnchor.parentNode) {
            console.warn(TOGGLE_BUTTON_REFERENCE_ELEMENT_NOT_FOUND_WARNING);
            return;
        }

        if (
            logoAnchor.previousElementSibling &&
            logoAnchor.previousElementSibling.classList.contains("mkdocs-toggle-sidebar-button")
        ) {
            return;
        }

        const btn = createDefaultToggleButton(toggleNavigation, toggleTOC);
        const logoStyle = window.getComputedStyle(logoAnchor);

        // If the logo sits in a named grid area or explicit grid track, align btn to the same track
        // and offset it immediately to the left of the logo
        if (logoStyle.gridArea && logoStyle.gridArea !== "auto") {
            btn.style.gridArea = logoStyle.gridArea;
            btn.style.justifySelf = "start";
            btn.style.transform = "translateX(calc(-100% - 0.5rem))";
        } else {
            if (logoStyle.order && logoStyle.order !== "0") {
                btn.style.order = logoStyle.order;
            }
            btn.style.marginRight = "0.5rem";
        }

        logoAnchor.parentNode.insertBefore(btn, logoAnchor);
    };

    const registerKeyboardEventHandler = () => {
        if (CONFIG.enableKeyboardShortcuts) {
            registerNativeHtmlKeyboardEventHandler();
        }
    };
    // END OF INCLUDE

    const coreEventListenerLogic = (keyChar) => {
        if (keyChar === "t") {
            toggleVisibility(false, true);
            return true;
        } else if (keyChar === "m") {
            toggleVisibility(true, false);
            return true;
        } else if (keyChar === "b") {
            toggleVisibility(true, true);
            return true;
        } else {
            return false;
        }
    };

    const onPageLoadedAction = () => {
        customDynamicStyle.innerHTML = setCombinedVisibility(loadNavigationState(), loadTocState());

        const toggle_button = CONFIG.toggleButton;
        if (toggle_button == "none") {
            // do nothing
        } else if (toggle_button == "navigation") {
            addToggleButton(true, false);
        } else if (toggle_button == "toc") {
            addToggleButton(false, true);
        } else if (toggle_button == "all") {
            addToggleButton(true, true);
        } else {
            console.error(`[mkdocs-toggle-sidebar-plugin] Unknown value for toggle_button: '${toggle_button}'`);
        }

        registerKeyboardEventHandler();
    };

    const createDefaultToggleButton = (toggleNavigation, toggleTOC) => {
        const toggleBtn = document.createElement("button");
        toggleBtn.type = "button";
        toggleBtn.className = "mkdocs-toggle-sidebar-button";
        toggleBtn.innerHTML = CONFIG.buttonIcon;
        if (toggleNavigation && toggleTOC) {
            toggleBtn.title = CONFIG.tooltips.both;
            toggleBtn.setAttribute("aria-label", CONFIG.tooltips.both);
        } else if (toggleNavigation) {
            toggleBtn.title = CONFIG.tooltips.nav;
            toggleBtn.setAttribute("aria-label", CONFIG.tooltips.nav);
        } else if (toggleTOC) {
            toggleBtn.title = CONFIG.tooltips.toc;
            toggleBtn.setAttribute("aria-label", CONFIG.tooltips.toc);
        }
        toggleBtn.addEventListener("click", () => toggleVisibility(toggleNavigation, toggleTOC));
        return toggleBtn;
    };

    // Export functions that the user can call to modify the state
    window.MkdocsToggleSidebarPlugin = {
        setNavigationVisibility: (show) => {
            saveBool("NAVIGATION", show);
            _setVisibility(show, loadTocState());
        },
        setTocVisibility: (show) => {
            saveBool("TOC", show);
            _setVisibility(loadNavigationState(), show);
        },
        setAllVisibility: (showNavigation, showTOC) => {
            saveBool("NAVIGATION", showNavigation);
            saveBool("TOC", showTOC);
            _setVisibility(showNavigation, showTOC);
        },
        toggleNavigationVisibility: () => toggleVisibility(true, false),
        toggleTocVisibility: () => toggleVisibility(false, true),
        toggleAllVisibility: () => toggleVisibility(true, true)
    };

    // Run this immediately instead of waiting for page.onload to prevent page flicker
    customDynamicStyle.innerHTML = setCombinedVisibility(loadNavigationState(), loadTocState());

    if (document.readyState === "loading") {
        document.addEventListener("DOMContentLoaded", onPageLoadedAction);
    } else {
        onPageLoadedAction();
    }
}());