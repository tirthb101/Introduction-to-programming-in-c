function checkmcq(event){
    let trigger = event.srcElement.innerHTML;
    if(trigger == "Nevada")
    {
        document.querySelector("#mcqresult").innerHTML = "correct";
        document.querySelector("#mcqresult").style.backgroundColor = "#00ff00";
        document.querySelector("#mcqresult").style.opacity = "1.0";
    }
    else
    {
        document.querySelector("#mcqresult").innerHTML = "Incorrect";
        document.querySelector("#mcqresult").style.backgroundColor = "#ff0000";
        document.querySelector("#mcqresult").style.opacity = "1.0";
    }
}




document.addEventListener("DOMContentLoaded", function (){
    document.querySelector("#check_ans").onclick = check;
    })

function check(){
    const ans = document.querySelector("#text_ans").value;
    if (ans == 'india' || ans == 'India')
    {
        document.querySelector("#resultans").innerHTML = "correct";
        document.querySelector("#resultans").style.backgroundColor = "#00ff00";
        document.querySelector("#resultans").style.opacity = "1.0";

    }
    else
    {
        document.querySelector("#resultans").innerHTML = "Incorrect";
        document.querySelector("#resultans").style.backgroundColor = "#ff0000";
        document.querySelector("#resultans").style.opacity = "1.0";
    }
}

