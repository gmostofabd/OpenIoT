/*
==================================================
    OpenIoT Framework
    theme.js
==================================================
*/

"use strict";

/*==================================================
    Theme Engine
==================================================*/

class ThemeManager {

    constructor() {

        this.button = document.getElementById("themeToggle");

        this.storageKey = "oif-theme";

        this.defaultTheme = "dark";

    }

    init() {

        const saved = localStorage.getItem(this.storageKey);

        if (saved) {

            this.setTheme(saved);

        }
        else {

            this.detectSystemTheme();

        }

        this.button.addEventListener("click", () => {

            this.toggle();

        });

    }

    detectSystemTheme() {

        if (window.matchMedia("(prefers-color-scheme: light)").matches) {

            this.setTheme("light");

        } else {

            this.setTheme("dark");

        }

    }

    toggle() {

        if (document.body.classList.contains("light-theme")) {

            this.setTheme("dark");

        } else {

            this.setTheme("light");

        }

    }

    setTheme(theme) {

        if (theme === "light") {

            document.body.classList.add("light-theme");

            this.button.innerHTML = "☀️";

        }
        else {

            document.body.classList.remove("light-theme");

            this.button.innerHTML = "🌙";

        }

        localStorage.setItem(this.storageKey, theme);

    }

}

const Theme = new ThemeManager();

document.addEventListener("DOMContentLoaded", () => {

    Theme.init();

});