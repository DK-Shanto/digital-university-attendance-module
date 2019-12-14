function addskill() {
    var number=Number(document.getElementById("skillnumber").value);
    if(number==2){
        alert("Maximum 3 Skills");
    }
    else
    {
        number=number+1;

        //Create an input type dynamically.
        var txtCVSkillHead = document.createElement("input");
        txtCVSkillHead.setAttribute("type", "text");
        txtCVSkillHead.setAttribute("name", "txtCVSkillHead_"+number);
        txtCVSkillHead.setAttribute("placeholder", "Skill header"); 
        txtCVSkillHead.setAttribute("class", "form-control");

        var txtCVSkillDetails = document.createElement("textarea");
        txtCVSkillDetails.setAttribute("name", "txtCVSkillDetails_"+number);
        txtCVSkillDetails.setAttribute("placeholder", "Skill description"); 
        txtCVSkillDetails.setAttribute("class", "form-control");
        txtCVSkillDetails.setAttribute("rows", "4");
        txtCVSkillDetails.setAttribute("cols", "50");
        txtCVSkillDetails.setAttribute("maxlength", "500");

        var breaker = document.createElement("br");

        var skillset = document.getElementById("skillset");

        skillset.appendChild(breaker);
        skillset.appendChild(txtCVSkillHead);
        skillset.appendChild(txtCVSkillDetails);

        document.getElementById('skillnumber').value = number;
    }
}
function addexperience() {
    var number=Number(document.getElementById("experiencenumber").value);
    if(number==2){
        alert("Maximum 3 Skills");
    }
    else
    {
        number=number+1;

        //Create an input type dynamically.
        var txtCVExperienceName = document.createElement("input");
        txtCVExperienceName.setAttribute("type", "text");
        txtCVExperienceName.setAttribute("name", "txtCVExperienceName_"+number);
        txtCVExperienceName.setAttribute("placeholder", "Experience Proffession Name"); 
        txtCVExperienceName.setAttribute("class", "form-control");

        var txtCVExperiencePost = document.createElement("input");
        txtCVExperiencePost.setAttribute("type", "text");
        txtCVExperiencePost.setAttribute("name", "txtCVExperiencePost_"+number);
        txtCVExperiencePost.setAttribute("placeholder", "Experience Proffession Post"); 
        txtCVExperiencePost.setAttribute("class", "form-control");

        var txtCVExperienceTimeSpan = document.createElement("input");
        txtCVExperienceTimeSpan.setAttribute("type", "text");
        txtCVExperienceTimeSpan.setAttribute("name", "txtCVExperienceTimeSpan_"+number);
        txtCVExperienceTimeSpan.setAttribute("placeholder", "Experience Proffession Time Span such as = 2007-2009"); 
        txtCVExperienceTimeSpan.setAttribute("class", "form-control");

        var txtCVExperienceDetails = document.createElement("textarea");
        txtCVExperienceDetails.setAttribute("name", "txtCVExperienceDetails_"+number);
        txtCVExperienceDetails.setAttribute("placeholder", "Experience Proffession description"); 
        txtCVExperienceDetails.setAttribute("class", "form-control");
        txtCVExperienceDetails.setAttribute("rows", "4");
        txtCVExperienceDetails.setAttribute("cols", "50");
        txtCVExperienceDetails.setAttribute("maxlength", "500");

        var breaker = document.createElement("br");

        var experienceset = document.getElementById("experienceset");

        experienceset.appendChild(breaker);
        experienceset.appendChild(txtCVExperienceName);
        experienceset.appendChild(txtCVExperiencePost);
        experienceset.appendChild(txtCVExperienceTimeSpan);
        experienceset.appendChild(txtCVExperienceDetails);

        document.getElementById('experiencenumber').value = number;
    }
}

function addeducation() {
    var number=Number(document.getElementById("educationnumber").value);
    if(number==3){
        alert("Maximum 4 Skills");
    }
    else
    {
        number=number+1;

        //Create an input type dynamically.
        var txtCVEducationInstituition = document.createElement("input");
        txtCVEducationInstituition.setAttribute("type", "text");
        txtCVEducationInstituition.setAttribute("name", "txtCVEducationInstituition_"+number);
        txtCVEducationInstituition.setAttribute("placeholder", "Experience Education Instituition"); 
        txtCVEducationInstituition.setAttribute("class", "form-control");

        var txtCVEducationSubject = document.createElement("input");
        txtCVEducationSubject.setAttribute("type", "text");
        txtCVEducationSubject.setAttribute("name", "txtCVEducationSubject_"+number);
        txtCVEducationSubject.setAttribute("placeholder", "Experience Education Subject"); 
        txtCVEducationSubject.setAttribute("class", "form-control");

        var txtCVEducationGPA = document.createElement("input");
        txtCVEducationGPA.setAttribute("type", "text");
        txtCVEducationGPA.setAttribute("name", "txtCVEducationGPA_"+number);
        txtCVEducationGPA.setAttribute("placeholder", "Experience Education GPA such as = 4.0"); 
        txtCVEducationGPA.setAttribute("class", "form-control");

        var breaker = document.createElement("br");

        var educationset = document.getElementById("educationset");

        educationset.appendChild(breaker);
        educationset.appendChild(txtCVEducationInstituition);
        educationset.appendChild(txtCVEducationSubject);
        educationset.appendChild(txtCVEducationGPA);

        document.getElementById('educationnumber').value = number;
    }
}