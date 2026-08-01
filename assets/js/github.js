/*
==================================================
    OpenIoT Framework
    github.js
==================================================
*/

"use strict";

/*
    CHANGE THESE TO YOUR REPOSITORY
*/
const GITHUB_OWNER = "gmostofabd";
const GITHUB_REPO = "OpenIoT";

const API = `https://api.github.com/repos/${GITHUB_OWNER}/${GITHUB_REPO}`;

class GitHubAPI {

    constructor() {

        this.repo = {};
        this.release = {};
        this.languages = {};
        this.contributors = [];

    }

    async initialize() {

        try {

            await Promise.all([

                this.loadRepository(),

                this.loadRelease(),

                this.loadLanguages(),

                this.loadContributors()

            ]);

            this.updateDashboard();

        }

        catch(error){

            console.error(error);

        }

    }

    async request(url){

        const response = await fetch(url);

        if(!response.ok)
            throw new Error(response.status);

        return response.json();

    }

    async loadRepository(){

        this.repo = await this.request(API);

    }

    async loadRelease(){

        try{

            this.release = await this.request(API + "/releases/latest");

        }

        catch{

            this.release = {};

        }

    }

    async loadLanguages(){

        this.languages = await this.request(API + "/languages");

    }

    async loadContributors(){

        this.contributors = await this.request(API + "/contributors");

    }

    update(id,value){

        const e=document.getElementById(id);

        if(e)
            e.textContent=value;

    }

    updateDashboard(){

        this.update("githubStars",this.repo.stargazers_count ?? 0);

        this.update("githubForks",this.repo.forks_count ?? 0);

        this.update("githubIssues",this.repo.open_issues_count ?? 0);

        this.update("githubWatchers",this.repo.watchers_count ?? 0);

        this.update("githubLicense",
            this.repo.license ?
            this.repo.license.spdx_id :
            "MIT");

        this.update("githubVersion",
            this.release.tag_name ??
            "Development");

        this.update("githubUpdated",
            new Date(this.repo.updated_at)
            .toLocaleDateString());

        this.update("githubContributors",
            this.contributors.length);

        this.drawLanguages();

    }

    drawLanguages(){

        const container=document.getElementById("languageChart");

        if(!container)
            return;

        container.innerHTML="";

        const total=Object.values(this.languages)
            .reduce((a,b)=>a+b,0);

        for(const lang in this.languages){

            const percent=((this.languages[lang]/total)*100)
                .toFixed(1);

            const item=document.createElement("div");

            item.className="language-row";

            item.innerHTML=`

                <div class="language-header">

                    <span>${lang}</span>

                    <span>${percent}%</span>

                </div>

                <div class="progress">

                    <div
                        class="progress-value"
                        style="width:${percent}%">
                    </div>

                </div>

            `;

            container.appendChild(item);

        }

    }

}

const GitHub = new GitHubAPI();

document.addEventListener("DOMContentLoaded",()=>{

    GitHub.initialize();

});
