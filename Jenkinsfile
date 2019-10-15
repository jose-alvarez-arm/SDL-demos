pipeline {
  agent any
  stages {
    stage('snyk') {
      steps {
        snykSecurity(snykTokenId: '223a828a-794f-42cc-b3bb-df2f6d0d790a', snykInstallation: 'Snyk', severity: 'high', projectName: 'SDL-demos', organisation: 'jose-alvarez-arm')
      }
    }
  }
}