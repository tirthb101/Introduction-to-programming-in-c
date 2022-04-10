let correct = 0;
let question_no = 0;

const questions = [
    {
        question: "What is capital of india?",
        options:["Delhi", "Mumbai", "Chennai", "Kolkata"],
        answer:"Delhi",
    },

    {
        question: "what is the text in the upper part of this site?",
        options: ["about us", "trivia", "home", "quiz"],
        answer:"trivia",
    },

    {
        question: "what is capital of maharastra?",
        options: ["pune", "kolkata", "ratnagiri", "mumbai"],
        answer:"mumbai",
    }
]



document.addEventListener("DOMContentLoaded", () => {
        load_question();

})

function load_question() {
    document.querySelector("#question").innerHTML = questions[question_no].question;
    const options = document.querySelector(".options");
    options.innerHTML = "";
    for (const option of questions[question_no].options)
    {
        options.innerHTML += `<button class="option">${option}</button>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp`;

    }
    document.querySelectorAll(".option").forEach( option  => {
        option.onclick = event => {
            let trigger = event.srcElement.innerHTML;
            if (trigger.localeCompare(questions[question_no].answer) == 0)
            {

                question_no++;
                correct++;
                document.querySelector("#correct").innerHTML = correct;
                document.querySelector("#outof").innerHTML = question_no;
                load_question();
            }
            else
            {
                question_no++;
                document.querySelector("#correct").innerHTML = correct;
                document.querySelector("#outof").innerHTML = question_no;
                load_question();

            }

        }
    })


}
