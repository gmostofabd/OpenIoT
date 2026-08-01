/*
====================================================
    OpenIoT Framework
    app.js
====================================================
*/

"use strict";

/*=============================================
    DOM Ready
=============================================*/

document.addEventListener("DOMContentLoaded", () => {

    initNavigation();

    initScrollReveal();

    initCounters();

    initSmoothScroll();

    initBackToTop();

    initActiveNavigation();

});

/*=============================================
    Sticky Navigation
=============================================*/

function initNavigation() {

    const header = document.getElementById("header");

    window.addEventListener("scroll", () => {

        if (window.scrollY > 50)
            header.classList.add("scrolled");
        else
            header.classList.remove("scrolled");

    });

}

/*=============================================
    Scroll Reveal
=============================================*/

function initScrollReveal() {

    const reveals = document.querySelectorAll(

        ".feature-card,.module-card,.doc-card,.timeline-item,.stat-card,.dashboard-card"

    );

    const observer = new IntersectionObserver(

        entries => {

            entries.forEach(entry => {

                if (entry.isIntersecting) {

                    entry.target.classList.add("active");

                }

            });

        },

        {

            threshold: .15

        }

    );

    reveals.forEach(item => {

        item.classList.add("reveal");

        observer.observe(item);

    });

}

/*=============================================
    Animated Counters
=============================================*/

function initCounters() {

    const counters = document.querySelectorAll(".stat-card h2");

    counters.forEach(counter => {

        const text = counter.innerText;

        const number = parseInt(text);

        if (isNaN(number))
            return;

        let value = 0;

        const timer = setInterval(() => {

            value++;

            counter.innerText = value;

            if (value >= number) {

                counter.innerText = text;

                clearInterval(timer);

            }

        },20);

    });

}

/*=============================================
    Smooth Scroll
=============================================*/

function initSmoothScroll() {

    document.querySelectorAll('a[href^="#"]').forEach(anchor => {

        anchor.addEventListener("click", e => {

            e.preventDefault();

            const target = document.querySelector(anchor.getAttribute("href"));

            if(target){

                target.scrollIntoView({

                    behavior:"smooth"

                });

            }

        });

    });

}

/*=============================================
    Back To Top
=============================================*/

function initBackToTop(){

    const button=document.createElement("div");

    button.className="fab";

    button.innerHTML="↑";

    document.body.appendChild(button);

    button.onclick=()=>{

        window.scrollTo({

            top:0,

            behavior:"smooth"

        });

    };

    window.addEventListener("scroll",()=>{

        if(window.scrollY>500)

            button.style.display="flex";

        else

            button.style.display="none";

    });

    button.style.display="none";

}

/*=============================================
    Active Navigation
=============================================*/

function initActiveNavigation(){

    const sections=document.querySelectorAll("section");

    const nav=document.querySelectorAll(".nav-links a");

    window.addEventListener("scroll",()=>{

        let current="";

        sections.forEach(section=>{

            const top=section.offsetTop-150;

            if(window.scrollY>=top)

                current=section.getAttribute("id");

        });

        nav.forEach(link=>{

            link.classList.remove("active");

            if(link.getAttribute("href")==="#"+current)

                link.classList.add("active");

        });

    });

}

/*=============================================
    Console Banner
=============================================*/

console.log(
`
======================================
 OpenIoT Framework
 Enterprise IoT for ESP32
 Version 3.0
======================================
`);