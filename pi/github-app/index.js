// index.js
// Main server code for GitHub App that listens to user's actions
// Maddie Zug & Simon Posada Fishman

const { execFile } = require('child_process')
const bodyParser = require('body-parser')

module.exports = app => {
  app.log('Yay, the app was loaded!')

  app.on('installation', async context => {
    const account = context.payload.installation.account
    console.log(account)
    if (account.type == 'Organization') {
      const result = await context.github.orgs.createHook({
        org: account.login,
        name: 'web',
        config: {
          url: process.env.WEBHOOK_PROXY_URL,
          content_type: 'json',
          secret: process.env.WEBHOOK_SECRET,
          events: ['pull_request', 'push']
        }
      })
      console.log(result)
    }
  })

  app.on('push', async context => {
    execFile('../c/matrix', ['firework'], (error, stdout, stderr) => {})
  })

  app.on('pull_request', async context => {
    execFile('../c/matrix', ['meteors'], (error, stdout, stderr) => {})
  })

  const router = app.route('/display')
  router.use(bodyParser.urlencoded({ extended: false }))
  router.get('/', (req, res) => {
    let text = req.query.text.toUpperCase()
    execFile('../c/matrix', [text], (error, stdout, stderr) => {})
    res.send('Displaying: ' + text)
  })
}
