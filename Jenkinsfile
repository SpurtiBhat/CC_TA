pipeline {
    agent any

    stages {
        stage('Clone repository') {
            steps {
                checkout([$class: 'GitSCM',
                    branches: [[name: '*/main']],
                    userRemoteConfigs: [[url: 'https://github.com/SPOORTHJ/CC_TA.git']]])
            }
        }
        
        stage('Build') {
            steps {
                sh 'g++ ./main/hi.cpp -o ./main/output' // Ensure the file path is correct
            }
        }

        stage('Test') {
            steps {
                script {
                    try {
                        sh './main/output' // Run the compiled program
                    } catch (Exception e) {
                        error 'Test stage failed! Check the output file path or compilation errors.'
                    }
                }
            }
        }

        stage('Deploy') {
            steps {
                echo 'Deploying application...'
            }
        }
    }

    post {
        success {
            echo 'Pipeline executed successfully!'
        }
        failure {
            echo 'Pipeline failed!'
            error 'Check the logs for more details.'
        }
    }
}
